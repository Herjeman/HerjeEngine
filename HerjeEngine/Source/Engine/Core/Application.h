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
		HE_API class HERenderer2D* GetRenderer() const;
		HE_API inline const float GetDeltaTime() const { return m_CurrentDeltaTime; }

	protected:
		// ----------- Game Accessors
		HE_API class HEWindow* GetWindow() { return m_Window.get(); }
		HE_API bool ShouldRun() const { return m_ShouldRun; }
		HE_API void Shutdown() { m_ShouldRun = false; }

		// ----------- Game Overrides
		HE_API virtual void PreLoop() {}
		HE_API virtual void Update(float deltaTime) {}
		HE_API virtual void Clean() {}


	private:
		void HandleInput();
		bool m_ShouldRun = true;
		uint64_t m_StartOfCycleRuntime = 0;
		uint64_t m_CurrentCycle = 0;
		float m_CurrentDeltaTime = 0.0f;

		float GetFrameTime();

	protected:
		// Do these need to be heap allocated?
		std::unique_ptr<class HEWindow> m_Window;
		std::unique_ptr<class HERenderer2D> m_Renderer;
		std::unique_ptr<class HEEntityComponentSystem> m_ECS;
	};

	Application* CreateApplication();

}

