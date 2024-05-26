#include <HerjeEngine.h>

class Game : public HerjeEngine::Application
{
public:
	Game()
	{}
	~Game(){}

	void Run() override
	{
		HE_LOG_TRACE("Hello from Game");
		while (ShouldRun())
		{
			SDL_Event event;
			SDL_PollEvent(&event);
			if (event.type == SDL_EVENT_QUIT)
			{
				Shutdown();
			}
		}
	}
};

HerjeEngine::Application* HerjeEngine::CreateApplication() 
{ 
	return new Game();
}