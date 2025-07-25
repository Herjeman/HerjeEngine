#pragma once
#include "Engine/ECS/ComponentRegistry.h"

namespace HerjeEngine
{
	struct HE_API RenderRectangleComponent
	{
		float xPos = 0;
		float yPos = 0;
		float Width = 1;
		float Height = 1;
	};

	struct HE_API HERect
	{
		Vector2 Origin;
		Vector2 Size;
	};

	class HERenderer2D
	{
	public:
		HERenderer2D(class HEWindow* window);
		~HERenderer2D();

		void PreRender();
		void Render();
		void PostRender();

		HE_API RenderRectangleComponent& AddRectangle(const EntityID ownerID, const RenderRectangleComponent& inRect);
		HE_API void RenderRectangles(const std::vector<HERect>& rectsToRender);

	private:

		void RenderRectangles_DEPRECATED();
		void RenderRectangle(const Vector2& origin, const Vector2& size);

	private:
		struct SDL_Renderer* m_Renderer;
		HEComponentRegistrySimple<RenderRectangleComponent> m_RectangleRegistry;
		std::vector<struct SDL_FRect> m_Renderables;
	};
}


