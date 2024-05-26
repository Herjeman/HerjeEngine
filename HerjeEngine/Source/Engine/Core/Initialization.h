#pragma once
#include "HerjeEngine.h"
#include <SDL3/SDL.h>

namespace HerjeEngine
{
	void InitializeDependencies()
	{
		if (SDL_Init(SDL_INIT_VIDEO) != 0) 
		{
			HE_ASSERT(false, SDL_GetError());
		}
		else
		{
			HE_LOG_CORE_INFO("SDL initialized");
		}
	}

	void ShutDownDependencies()
	{
		SDL_Quit();
		HE_LOG_CORE_INFO("SDL shutdown");
	}
}