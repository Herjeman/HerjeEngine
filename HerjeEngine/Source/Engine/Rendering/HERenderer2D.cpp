#include "HEPreCompiled.h"
#include <SDL3/SDL_render.h>
#include <random>

#include "Engine/Core/HEWindow.h"
#include "HERenderer2D.h"



namespace HerjeEngine
{
	HERenderer2D::HERenderer2D(HEWindow* window)
	{
		// Should we create and destroy the renderer here? Why not just let the window own it?
		m_Renderer = SDL_CreateRenderer(window->GetWindow(), NULL);
		HE_CORE_ASSERT(m_Renderer, SDL_GetError());
	}

	HERenderer2D::~HERenderer2D()
	{
		SDL_DestroyRenderer(m_Renderer);
	}

	void HERenderer2D::Render()
	{
		// Not sure what to do here for now... not really how things turned out...
	}

	RenderRectangleComponent& HERenderer2D::AddRectangle(const EntityID ownerID, const RenderRectangleComponent& inRect)
	{
		return m_RectangleRegistry.AddComponent(ownerID, inRect);
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

	void HERenderer2D::RenderRectangles_DEPRECATED()
	{
		if (m_RectangleRegistry.Count() == 0)
		{
			return;
		}

		SDL_SetRenderDrawColor(m_Renderer, 255, 255, 255, 255);

		std::vector<SDL_FRect> rectsToRender;
		rectsToRender.reserve(m_RectangleRegistry.Count());

		for (const auto& rect : m_RectangleRegistry.GetComponents())
		{
			rectsToRender.push_back({ rect.xPos, rect.yPos, rect.Width, rect.Height });
		}

		if (SDL_RenderFillRects(m_Renderer, &rectsToRender[0], static_cast<int>(rectsToRender.size() - 1)) < 0)
		{
			const char* error = SDL_GetError();
			HE_CORE_ASSERT(false, error);
		}
	}

	void HERenderer2D::RenderRectangles(const std::vector<HERect>& rectsToRender)
	{
		SDL_SetRenderDrawColor(m_Renderer, 255, 255, 255, 255);
		std::vector<SDL_FRect> sdlRects;
		sdlRects.reserve(rectsToRender.size());

		for (const auto& rect : rectsToRender)
		{
			sdlRects.push_back({ rect.Origin.X, rect.Origin.Y, rect.Size.X, rect.Size.Y });
		}

		if (SDL_RenderFillRects(m_Renderer, &sdlRects[0], static_cast<int>(sdlRects.size())))
		{
			const char* error = SDL_GetError();
			HE_CORE_ASSERT(false, error);
		}
	}

	void HERenderer2D::RenderRectangle(const Vector2& Origin, const Vector2& Size)
	{
		SDL_SetRenderDrawColor(m_Renderer, 255, 255, 255, 255);
		SDL_FRect rect = SDL_FRect{ Origin.X, Origin.Y, Size.X,Size.Y };
		SDL_RenderFillRect(m_Renderer, &rect);
	}
}
