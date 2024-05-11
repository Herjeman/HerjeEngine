#include <HerjeEngine.h>

class Game : public HerjeEngine::Application
{
public:
	Game(){}
	~Game(){}
};

HerjeEngine::Application* HerjeEngine::CreateApplication() 
{ 
	return new Game(); 
}