#pragma once
#include "Engine/Core.h"

namespace HerjeEngine {

	class HE_API Application
	{
	public:
		Application() {}

		virtual ~Application(){}

		virtual void Run();
	};

	Application* CreateApplication();
}

