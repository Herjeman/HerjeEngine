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

	class HERenderer2D
	{
	public:
		HERenderer2D(class HEWindow* window);
		~HERenderer2D();

		void Render();

		HE_API RenderRectangleComponent& AddRectangle(const EntityID ownerID, const RenderRectangleComponent& inRect);

	private:
		void PreRender();
		void PostRender();

		void RenderRectangles();
		void RenderSquare(const Vector2& Origin, const Vector2& Size);

	private:
		struct SDL_Renderer* m_Renderer;
		HEComponentRegistrySimple<RenderRectangleComponent> m_RectangleRegistry;
	};
}


