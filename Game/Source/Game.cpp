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
		const auto Entity = m_ECS->AddEntity();
		HerjeEngine::LocationComponent Loc = { HerjeEngine::Vector2{200, 300} };
		HerjeEngine::RectangleComponent Rec = { HerjeEngine::Vector2{20, 30} };

		m_ECS->LocationComponents.SetComponent(Entity, Loc, m_ECS->EntityManager);
		m_ECS->RectangleComponents.SetComponent(Entity, Rec, m_ECS->EntityManager);

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

private:
	float m_TotalRuntime = 0.0f;
	HerjeEngine::InputActionHandle m_PrintInputActionHandle;
	HerjeEngine::InputActionHandle m_RebindInputActionHandle;
};

HerjeEngine::Application* HerjeEngine::CreateApplication()
{
	return new Game();
}