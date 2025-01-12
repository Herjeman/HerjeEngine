#pragma once
#include "HEPreCompiled.h"
#include "Engine/Events/Event.h"

namespace HerjeEngine
{
	enum InputEventID : uint32_t
	{
		QUIT
	};

	struct InputEvent
	{
		InputEventID EventSignature = InputEventID::QUIT;
	};

	class InputSystem
	{
	public:
		InputSystem(const InputSystem&) = delete;
		InputSystem& operator= (const InputSystem&) = delete;

		HE_API static InputSystem& Get();
		void ProcessInput();

		EventDispatcher<InputEvent>& GetInputEventDispatcher() { return m_InputEventDispatcher; }

	private:
		InputSystem();
		~InputSystem();

		EventDispatcher<InputEvent> m_InputEventDispatcher;
	};
}

