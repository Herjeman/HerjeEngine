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
		m_Runtime = 0;
		m_NextLog = 20000;

		const auto Entity = m_ECS->AddEntity();
		HerjeEngine::LocationComponent Loc = { HerjeEngine::Vector2{200, 300} };
		HerjeEngine::RectangleComponent Rec = { HerjeEngine::Vector2{20, 30} };

		m_ECS->LocationComponents.SetComponent(Entity, Loc, m_ECS->EntityManager);
		m_ECS->RectangleComponents.SetComponent(Entity, Rec, m_ECS->EntityManager);
	}

	void Update(float deltaTime) override
	{
		m_Runtime += static_cast<int>(deltaTime);
		if (m_Runtime >= 250000)
		{
			std::string msg = "Shutting down after: ";
			msg.append(std::to_string(m_Runtime));
			msg.append(" cycles.");
			HE_LOG_INFO(msg);
			Shutdown();
			return;
		}
		if (m_Runtime >= m_NextLog)
		{
			HE_LOG_TRACE("Running...");
			m_NextLog += 20000;
		}
	}

	void Clean() override
	{
		m_Runtime = 0;
	}

private:
	int m_Runtime = 0;
	int m_NextLog = 0;
};

HerjeEngine::Application* HerjeEngine::CreateApplication()
{
	return new Game();
}