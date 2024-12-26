#pragma once

namespace HerjeEngine
{
	class HERenderer2D
	{
	public:
		HERenderer2D(struct SDL_Window* window);
		~HERenderer2D();

		void PreRender();
		void PostRender();

		void RenderSquare(const Vector2& Origin, const Vector2& Size);

	private:
		struct SDL_Renderer* m_Renderer;
	};	
}


