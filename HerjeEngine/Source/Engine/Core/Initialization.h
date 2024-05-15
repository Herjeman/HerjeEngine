#pragma once
#include "HerjeEngine.h"
#include <SDL3/SDL.h>

namespace HerjeEngine
{
	void InitializeDependencies()
	{
		SDL_Init(SDL_INIT_VIDEO);
		HE_LOG_CORE_INFO("SDL initialized");
	}

	void ShutDownDependencies()
	{
		SDL_Quit();
		HE_LOG_CORE_INFO("SDL shutdown");
	}
}