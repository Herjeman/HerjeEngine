#include <HerjeEngine.h>
#include <Engine/ECS/HEEntityComponentSystem.h>

class Game : public HerjeEngine::Application
{
public:
	Game(){}
	~Game(){}

	void PreLoop() override 
	{

		auto& ECS = HerjeEngine::HEEntityComponentSystem::Get();
		ECS.AddEntity(static_cast<uint64_t>(HerjeEngine::EEntitySignature::Transform));

		m_Runtime = 0;
		m_NextLog = 20000000;
	}

	void Update(float deltaTime) override
	{
		m_Runtime += (int)deltaTime;
		if (m_Runtime >= 250000000)
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
			m_NextLog += 20000000;
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