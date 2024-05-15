#include <HerjeEngine.h>

class Game : public HerjeEngine::Application
{
public:
	Game(){}
	~Game(){}

	void Run() override
	{
		HE_LOG_TRACE("Hello from Game");
	}
};

HerjeEngine::Application* HerjeEngine::CreateApplication() 
{ 
	return new Game(); 
}