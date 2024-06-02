#include <HerjeEngine.h>

class Game : public HerjeEngine::Application
{
public:
	Game(){}
	~Game(){}

	void PreLoop() override 
	{
		m_Runtime = 0;
		m_NextLog = 1000000;
	}

	void Update(float deltaTime) override
	{
		m_Runtime += (int)deltaTime;
		if (m_Runtime >= 1000000000)
		{
			std::string msg = "Runtime: ";
			msg.append(std::to_string(m_Runtime));
			HE_LOG_TRACE(msg);
			HE_LOG_INFO("Shutting down");
			Shutdown();
			return;
		}
		if (m_Runtime >= m_NextLog)
		{
			std::string msg = "Runtime: ";
			msg.append(std::to_string(m_Runtime));
			HE_LOG_TRACE(msg);
			m_NextLog += 1000000;
		}
	}

	void Clean() override
	{
		m_Runtime = 0;
	}

private:
	int m_Runtime;
	int m_NextLog;
};

HerjeEngine::Application* HerjeEngine::CreateApplication() 
{ 
	return new Game();
}