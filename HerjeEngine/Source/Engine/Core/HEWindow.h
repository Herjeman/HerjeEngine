#pragma once
#include "Utilities/Vector2.h"
#include <SDL3/SDL_video.h>

namespace HerjeEngine {

	struct HEWindowData {
		const char* Title = "";
		Vector2 Dimensions = { 800, 600 };

		// Maybe some option to pass flags?

	};

	class HEWindow
	{
		friend class HERenderer2D;

	public:
		HEWindow();
		~HEWindow();

		void Update();

		const inline Vector2& GetDimensions() const { return m_WindowData.Dimensions; }
		const inline char* GetTitle() const { return m_WindowData.Title; }
		SDL_Window* GetWindow() { return m_Window; }

	protected:

	private:
		SDL_Window* m_Window;
		HEWindowData m_WindowData = {};
	};

}
