#pragma once

namespace HerjeEngine
{
	class HERenderer2D
	{
	public:
		HERenderer2D(struct SDL_Window* window);
		~HERenderer2D();

		void RenderEntities();

	private:
		struct SDL_Renderer* m_Renderer;
	};	
}


