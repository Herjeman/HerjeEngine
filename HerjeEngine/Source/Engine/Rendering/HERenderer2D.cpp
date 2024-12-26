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

	void HERenderer2D::PreRender()
	{
		SDL_SetRenderDrawColor(m_Renderer, 0, 0, 0, 0);
		SDL_RenderClear(m_Renderer);
	}

	void HERenderer2D::PostRender()
	{
		SDL_RenderPresent(m_Renderer);
	}

	void HERenderer2D::RenderSquare(const Vector2& Origin, const Vector2& Size)
	{
		SDL_SetRenderDrawColor(m_Renderer, 255, 255, 255, 255);
		SDL_FRect rect = SDL_FRect{ Origin.X, Origin.Y, Size.X,Size.Y };
		SDL_RenderFillRect(m_Renderer, &rect);
	}
}
