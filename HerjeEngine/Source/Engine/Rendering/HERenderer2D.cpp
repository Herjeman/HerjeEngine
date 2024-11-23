#include "HEPreCompiled.h"
#include <SDL3/SDL_render.h>
#include "Engine/Core/HEWindow.h"
#include "HERenderer2D.h"


namespace HerjeEngine
{
	HERenderer2D::HERenderer2D(SDL_Window* window)
	{
		m_Renderer = SDL_CreateRenderer(window, NULL);
		HE_CORE_ASSERT(m_Renderer, SDL_GetError());
	}

	HERenderer2D::~HERenderer2D()
	{
		SDL_DestroyRenderer(m_Renderer);
	}

	void HERenderer2D::RenderEntities()
	{

	}
}
