#include "HEPreCompiled.h"
#include "InputSystem.h"
#include "SDL3/SDL.h"

namespace HerjeEngine
{
	InputSystem::InputSystem()
	{
	}

	InputSystem::~InputSystem()
	{
	}

	InputSystem& InputSystem::Get()
	{
		static InputSystem inputSystem;
		return inputSystem;
	}

	void InputSystem::ProcessInput()
	{
		SDL_Event event;
		while (SDL_PollEvent(&event) != 0)
		{
			if (event.type == SDL_EVENT_QUIT)
			{
				InputEvent QuitEvent;
				m_InputEventDispatcher.DispatchEvent(QuitEvent);
			}
		}
	}
}


