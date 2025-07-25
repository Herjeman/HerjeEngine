#include "HEPreCompiled.h"
#include "Application.h"
#include "HEWindow.h"
#include "Engine/ECS/HEECS.h"
#include "Engine/Input/InputSystem.h"
#include "Engine/Rendering/HERenderer2D.h"
#include "SDL3/SDL_timer.h"


namespace HerjeEngine
{
	static constexpr float MILLISECOND_MULTIPLIER = 0.001f;

	Application::Application()
	{
		m_Window = std::make_unique<HEWindow>();
		HE_CORE_ASSERT(m_Window, "HE Window creation failed");

		m_Renderer = std::make_unique<HERenderer2D>(m_Window.get());
		HE_CORE_ASSERT(m_Renderer, "HERenderer creation failed");

		m_ECS = std::make_unique<HEEntityComponentSystem>();
		HE_CORE_ASSERT(m_ECS, "ECS creation failed");
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

		const float loopStartTime = SDL_GetTicks();
		std::string msg = "Starting main loop after: ";
		msg.append(std::to_string(loopStartTime * MILLISECOND_MULTIPLIER));
		msg.append(" seconds.\n");
		HE_LOG_CORE_INFO(msg);

		while (m_ShouldRun)
		{
			m_CurrentDeltaTime = GetFrameTime();
			m_Renderer->PreRender();

			HandleInput();
			Update(m_CurrentDeltaTime);
			Draw();

			m_Renderer->PostRender();
			m_CurrentCycle++;
		}

		const float totalRuntime = SDL_GetTicks();

		msg = "Shutting down after: ";
		msg.append(std::to_string(totalRuntime * MILLISECOND_MULTIPLIER));
		msg.append(" seconds.\n");
		msg.append("Average frametime: ");
		msg.append(std::to_string((totalRuntime - loopStartTime) / m_CurrentCycle));
		msg.append(" milliseconds.\n");
		HE_LOG_CORE_INFO(msg);

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

		return frameTime * MILLISECOND_MULTIPLIER;
	}
}