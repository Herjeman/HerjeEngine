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

	void PreLoop() override {}

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

private:
	float m_TotalRuntime = 0.0f;

};

HerjeEngine::Application* HerjeEngine::CreateApplication()
{
	return new Game();
}