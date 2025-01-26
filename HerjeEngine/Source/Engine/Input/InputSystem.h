#pragma once
#include "HEPreCompiled.h"
#include "Engine/Events/Event.h"

union SDL_Event;

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

	enum EInputActionState : uint8_t
	{
		CANCELED,
		TRIGGERED
	};

	struct InputActionCallbackPayload
	{
		EInputActionState State = EInputActionState::CANCELED;
		InputActionCallbackPayload(EInputActionState state) :
			State(state) {}
	};

	typedef std::function<void(const InputActionCallbackPayload&)> InputActionCallback;
	struct InputAction
	{
		InputAction(const std::vector<HE_KeyCode>& keys, const InputActionCallback& callback);
		void ProcessInputEvent(const SDL_Event& Event);

		EInputActionState State = EInputActionState::CANCELED;
		std::unordered_map<HE_KeyCode, bool> InputSignature;
		InputActionCallback Callback;
	};

	struct InputActionHandle
	{
		size_t ID;
	};

	class InputSystem
	{
	public:
		InputSystem(const InputSystem&) = delete;
		InputSystem& operator= (const InputSystem&) = delete;

		HE_API static InputSystem& Get();
		void ProcessInput();

		EventDispatcher<InputEvent>& GetInputEventDispatcher() { return m_InputEventDispatcher; }

		HE_API InputActionHandle AddInputAction(const std::vector<HE_KeyCode>& keys, InputActionCallback callback);
		HE_API const std::unordered_map<HE_KeyCode, bool>* GetInputActionSignature(const InputActionHandle& handle);
		HE_API void RemoveInputAction(const InputActionHandle& handle);
		HE_API bool RebindInputAction(const InputActionHandle& handle, const std::vector<HE_KeyCode>& keys);

	private:
		InputAction* GetInputAction(const InputActionHandle& handle);
		InputSystem();
		~InputSystem();

		EventDispatcher<InputEvent> m_InputEventDispatcher;
		std::vector<InputAction> InputActions;
	};
}

