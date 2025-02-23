#include "HEPreCompiled.h"
#include "InputSystem.h"
#include "SDL3/SDL.h"

namespace HerjeEngine
{
	HE_API InputActionHandle InputSystem::AddInputAction(const std::vector<HE_KeyCode>& keys, InputActionCallback callback)
	{
		InputActions.push_back(InputAction(keys, callback));
		return InputActionHandle{ InputActions.size() - 1 };
	}
	const std::unordered_map<HE_KeyCode, bool>* InputSystem::GetInputActionSignature(const InputActionHandle& handle)
	{
		const auto* retVal = GetInputAction(handle);
		if (retVal == nullptr)
		{
			return nullptr;
		}

		return &retVal->InputSignature;
	}

	void InputSystem::RemoveInputAction(const InputActionHandle& handle)
	{
		InputActions.erase(InputActions.begin() + handle.ID);
	}

	InputAction* InputSystem::GetInputAction(const InputActionHandle& handle)
	{
		if (handle.ID > InputActions.size())
		{
			HE_CORE_ASSERT(handle.ID > InputActions.size(), "Trying to get an Input action with an invalid handle");
			return nullptr;
		}
		return &InputActions[handle.ID];
	}

	bool InputSystem::RebindInputAction(const InputActionHandle& handle, const std::vector<HE_KeyCode>& keys)
	{
		InputAction* Action = GetInputAction(handle);
		if (Action == nullptr)
		{
			return false;
		}

		Action->InputSignature.clear();
		for (const auto& key : keys)
		{
			Action->InputSignature.insert({ key, false });
		}
		return true;
	}

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
			constexpr uint32_t keyboardEventFlag = 0x300;
			constexpr uint32_t mouseEventFlag = 0x400;

			if (event.type == SDL_EVENT_QUIT)
			{
				HE_LOG_CORE_TRACE("Registered QUIT input event");
				InputEvent QuitEvent;
				m_InputEventDispatcher.DispatchEvent(QuitEvent);
			}

			if ((event.type & keyboardEventFlag) == keyboardEventFlag || (event.type & mouseEventFlag) == mouseEventFlag)
			{
				for (auto& inputAction : InputActions)
				{
					bool consumedInput = inputAction.ProcessInputEvent(event);
				}
			}
		}
	}

	InputAction::InputAction(const std::vector<HE_KeyCode>& keys, const InputActionCallback& callback)
	{
		for (const auto& key : keys)
		{
			InputSignature.insert({ key, false });
		}

		Callback = callback;
	}

	bool InputAction::ProcessInputEvent(const SDL_Event& Event)
	{
		bool consumedInput = false;

		// Update Action state
		bool keyPressed = Event.type == SDL_EVENT_KEY_DOWN;
		std::unordered_map<HE_KeyCode, bool>::iterator KeyIndex = InputSignature.find(Event.key.keysym.sym);
		if (KeyIndex != InputSignature.end())
		{
			InputSignature.at(Event.key.keysym.sym) = keyPressed;
			consumedInput = ConsumeInput && keyPressed;
		}

		// Evaluate trigger conditions
		EInputActionState newState = EInputActionState::TRIGGERED;
		for (const auto& Key : InputSignature)
		{
			// All keys are not being held
			if (Key.second == false)
			{
				newState = EInputActionState::CANCELED;
				break;
			}
		}

		if (newState == State)
		{
			// Don't propagate unchanged state
			return consumedInput;
		}
		State = newState;
		InputActionCallbackPayload Payload{ State };
		Callback(Payload);
		return consumedInput;
	}
}


