#include "HEPreCompiled.h"
#include "Application.h"
#include "HEWindow.h"
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

	Application::~Application(){}

	void Application::Run() 
	{
		PreLoop();

		while (m_ShouldRun)
		{
			Update(1.0f);
			Render();
		}

		Clean();
	}

	void Application::Render()
	{
		m_Renderer->PreRender();

		const Vector2& WindowDimensions = m_Window->GetDimensions();
		m_Renderer->RenderSquare({WindowDimensions.X * 0.5f, WindowDimensions.Y * 0.5f}, {500.f, 200.f});

		m_Renderer->PostRender();
	}


}