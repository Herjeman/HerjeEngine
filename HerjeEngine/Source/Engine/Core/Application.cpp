#include "HEPreCompiled.h"
#include "Application.h"
#include "HEWindow.h"
#include "Engine/ECS/HEECS.h"
#include "Engine/Input/InputSystem.h"
#include "Engine/Rendering/HERenderer2D.h"
#include "SDL3/SDL_timer.h"

namespace HerjeEngine
{
	Application::Application()
	{
		m_Window = std::make_unique<HEWindow>();
		HE_CORE_ASSERT(m_Window, "HE Window creation failed");

		m_Renderer = std::make_unique<HERenderer2D>(m_Window.get()->GetWindow());
		HE_CORE_ASSERT(m_Renderer, "HERenderer creation failed");

		m_ECS = std::make_unique<HEEntityComponentSystem>();
		HE_CORE_ASSERT(m_ECS, "ECS freation failed");
	}

	Application::~Application() {}

	void Application::Run()
	{
		PreLoop();
		EventListener<InputEvent> quitEventListener(
			[this](const InputEvent& event)
			{
				if (event.EventSignature == InputEventID::QUIT)
				{
					Shutdown();
				}
			},
			InputSystem::Get().GetInputEventDispatcher());

		while (m_ShouldRun)
		{
			float deltaTime = GetFrameTime();

			m_Renderer->PreRender();
			HandleInput();
			Update(deltaTime);
			m_ECS->ProcessSystems(*this);
			m_Renderer->PostRender();

			m_CurrentCycle++;
		}

		Clean();
	}

	HERenderer2D* Application::GetRenderer() const
	{
		return m_Renderer.get();
	}

	void Application::HandleInput()
	{
		InputSystem::Get().ProcessInput();
	}

	float Application::GetFrameTime()
	{
		uint64_t CurrentRuntime = SDL_GetTicks();
		uint64_t frameTime = CurrentRuntime - m_StartOfCycleRuntime;
		m_StartOfCycleRuntime = CurrentRuntime;

#ifdef HE_CONFIGURATION_DEBUG
		if (frameTime > HE_MAX_DEBUG_CYCLETIME)
		{
			frameTime = HE_MAX_DEBUG_CYCLETIME;
		}
#endif // HE_CONFIGURATION_DEBUG

		return frameTime * 0.001f;
	}
}