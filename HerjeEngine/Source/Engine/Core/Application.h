#pragma once
#include "HEPreCompiled.h"
#include "Engine/Core.h"

namespace HerjeEngine {

	class Application
	{
	public:
		HE_API Application();

		HE_API virtual ~Application();

		HE_API virtual void Run();

	protected:
		HE_API class HEWindow* GetWindow() { return m_Window.get(); }
		HE_API bool ShouldRun() { return m_ShouldRun; }
		HE_API void Shutdown() { m_ShouldRun = false; }

	private:
		bool m_ShouldRun = true;
		std::unique_ptr<class HEWindow> m_Window;
	};

	Application* CreateApplication();

}

