#include <HerjeEngine.h>
#include <Engine/ECS/HEECS.h>
#include <Utilities/Vector2.h>
#include <Engine/Input/InputSystem.h>
#include <Engine/Input/HEKeycodes.h>

class Game : public HerjeEngine::Application
{
public:
	Game() {}
	~Game() {}

	void PreLoop() override
	{
		Player = m_ECS->AddEntity();
		HerjeEngine::LocationComponent loc = { HerjeEngine::Vector2{200, 300} };
		HerjeEngine::RectangleComponent rec = { HerjeEngine::Vector2{20, 30} };
		HerjeEngine::MovementComponent mov = { HerjeEngine::Vector2{0, 0} };

		m_ECS->LocationComponents.SetComponentForEntity(Player, loc, m_ECS->EntityManager);
		m_ECS->RectangleComponents.SetComponentForEntity(Player, rec, m_ECS->EntityManager);
		m_ECS->MovementComponents.SetComponentForEntity(Player, mov, m_ECS->EntityManager);

		HerjeEngine::InputSystem& inputSystem = HerjeEngine::InputSystem::Get();
		std::vector<HE_KeyCode> inputs{ HE_KEY_SPACE };
		m_PrintInputActionHandle = inputSystem.AddInputAction(inputs, [&](const HerjeEngine::InputActionCallbackPayload& payload)
			{
				PrintInput(payload);
			});

		inputs.clear();
		inputs.push_back(HE_KEY_LSHIFT);
		inputs.push_back(HE_KEY_SPACE);
		m_RebindInputActionHandle = inputSystem.AddInputAction(inputs, [&](const HerjeEngine::InputActionCallbackPayload& payload)
			{
				RebindInputAction(payload);
			});

		inputs.clear();
		inputs.push_back(HE_KEY_UP);
		m_UpInputActionHandle = inputSystem.AddInputAction(inputs, [&](const HerjeEngine::InputActionCallbackPayload& payload)
			{
				UpdatePlayerMovement(payload, HerjeEngine::Vector2::Up());
			});

		inputs.clear();
		inputs.push_back(HE_KEY_DOWN);
		m_DownInputActionHandle = inputSystem.AddInputAction(inputs, [&](const HerjeEngine::InputActionCallbackPayload& payload)
			{
				UpdatePlayerMovement(payload, HerjeEngine::Vector2::Down());
			});

		inputs.clear();
		inputs.push_back(HE_KEY_LEFT);
		m_LeftInputActionHandle = inputSystem.AddInputAction(inputs, [&](const HerjeEngine::InputActionCallbackPayload& payload)
			{
				UpdatePlayerMovement(payload, HerjeEngine::Vector2::Left());
			});

		inputs.clear();
		inputs.push_back(HE_KEY_RIGHT);
		m_RightInputActionHandle = inputSystem.AddInputAction(inputs, [&](const HerjeEngine::InputActionCallbackPayload& payload)
			{
				UpdatePlayerMovement(payload, HerjeEngine::Vector2::Right());
			});
	}

	void Update(float deltaTime) override
	{
		m_TotalRuntime += deltaTime;
	}

	void Clean() override
	{
		std::string msg = "Shutting down after: ";
		msg.append(std::to_string(m_TotalRuntime));
		msg.append(" seconds.");
		HE_LOG_CORE_INFO(msg);
	}

	void PrintInput(const HerjeEngine::InputActionCallbackPayload& payload) const
	{
		bool triggered = payload.State == HerjeEngine::EInputActionState::TRIGGERED;
		if (triggered)
		{
			HE_LOG_INFO("Input Action triggered");
		}
		else
		{

			HE_LOG_INFO("Input Action cancelled");
		}
	}

	void RebindInputAction(const HerjeEngine::InputActionCallbackPayload& payload) const
	{
		if (payload.State == HerjeEngine::EInputActionState::TRIGGERED)
		{
			HE_LOG_INFO("Rebinding input");
			auto& InputSystem = HerjeEngine::InputSystem::Get();

			const auto* InputSignature = InputSystem.GetInputActionSignature(m_PrintInputActionHandle);
			if (InputSignature == nullptr)
			{
				HE_ASSERT(InputSignature, "Bad handle? wtf?");
				return;
			}

			if (InputSignature->empty())
			{
				return;
			}

			HE_KeyCode oldKey = InputSignature->begin()->first;
			HE_KeyCode newKey = HE_KEY_SPACE;
			if (oldKey == HE_KEY_SPACE)
			{
				newKey = HE_KEY_W;
			}
			InputSystem.RebindInputAction(m_PrintInputActionHandle, { newKey });
		}
	}

	void UpdatePlayerMovement(const HerjeEngine::InputActionCallbackPayload& payload, HerjeEngine::Vector2 updateDirection)
	{
		auto* movementComponent = m_ECS->MovementComponents.GetComponentForEntity(Player);
		if (movementComponent == nullptr)
		{
			HE_ASSERT(movementComponent, "Bad player index?");
			return;
		}

		if (payload.State == HerjeEngine::EInputActionState::TRIGGERED)
		{
			movementComponent->Velocity = movementComponent->Velocity + updateDirection * PlayerMoveSpeed;
		}
		else
		{
			movementComponent->Velocity = movementComponent->Velocity - updateDirection * PlayerMoveSpeed;
		}
	}

private:
	float m_TotalRuntime = 0.0f;
	float PlayerMoveSpeed = 80.0f;
	EntityID Player;

	HerjeEngine::InputActionHandle m_PrintInputActionHandle;
	HerjeEngine::InputActionHandle m_RebindInputActionHandle;
	HerjeEngine::InputActionHandle m_UpInputActionHandle;
	HerjeEngine::InputActionHandle m_DownInputActionHandle;
	HerjeEngine::InputActionHandle m_LeftInputActionHandle;
	HerjeEngine::InputActionHandle m_RightInputActionHandle;
};

HerjeEngine::Application* HerjeEngine::CreateApplication()
{
	return new Game();
}