#include <HerjeEngine.h>
#include <Engine/ECS/HEECS.h>
#include <Utilities/Vector2.h>

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

private:
	float m_TotalRuntime = 0.0f;
};

HerjeEngine::Application* HerjeEngine::CreateApplication()
{
	return new Game();
}