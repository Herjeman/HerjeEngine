#include "HEPreCompiled.h"
#include "Application.h"
#include "HEWindow.h"


namespace HerjeEngine
{
	Application::Application()
	{
		m_Window = std::make_unique<HEWindow>();
	}

	Application::~Application()
	{
	}

	void Application::Run() {}


}