#include "HEPreCompiled.h"
#include "Application.h"
#include "HEWindow.h"
#include "Engine/Input/InputSystem.h"
#include "Engine/Rendering/HERenderer2D.h"

namespace HerjeEngine
{
	Application::Application()
	{
		m_Window = std::make_unique<HEWindow>();
		HE_CORE_ASSERT(m_Window, "HE Window creation failed");

		m_Renderer = std::make_unique<HERenderer2D>(m_Window.get()->GetWindow());
		HE_CORE_ASSERT(m_Renderer, "HERenderer creation failed");

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
			HandleInput();
			Update(1.0f);
			Render();
		}

		Clean();
	}

	void Application::HandleInput()
	{
		InputSystem::Get().ProcessInput();
	}

	void Application::Render()
	{
		m_Renderer->PreRender();

		const Vector2& WindowDimensions = m_Window->GetDimensions();
		m_Renderer->RenderSquare({ WindowDimensions.X * 0.5f, WindowDimensions.Y * 0.5f }, { 500.f, 200.f });

		m_Renderer->PostRender();
	}


}