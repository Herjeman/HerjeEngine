#pragma once
#include "HEPreCompiled.h"
#include "Engine/Core.h"

namespace HerjeEngine {

	class Application
	{
	public:
		HE_API Application();

		HE_API virtual ~Application();

		HE_API void Run();

	protected:
		// ----------- Game Accessors
		HE_API class HEWindow* GetWindow() { return m_Window.get(); }
		HE_API bool ShouldRun() { return m_ShouldRun; }
		HE_API void Shutdown() { m_ShouldRun = false; }

		// ----------- Game Overrides
		HE_API virtual void PreLoop(){}
		HE_API virtual void Update(float deltaTime){}
		HE_API virtual void Clean(){}


	private:
		void Render();

	private:
		bool m_ShouldRun = true;

		// Should I put these on stack?
		std::unique_ptr<class HEWindow> m_Window;
		std::unique_ptr<class HERenderer2D> m_Renderer;
	};

	Application* CreateApplication();

}

