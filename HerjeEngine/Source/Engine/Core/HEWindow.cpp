#include "HEPreCompiled.h"
#include "HEWindow.h"


HerjeEngine::HEWindow::HEWindow()
{
	m_Window = SDL_CreateWindow(m_WindowData.Title, (int)m_WindowData.Dimensions.X, (int)m_WindowData.Dimensions.Y, 0);
	HE_CORE_ASSERT(m_Window, SDL_GetError());
}

HerjeEngine::HEWindow::~HEWindow()
{
	SDL_DestroyWindow(m_Window);
}

void HerjeEngine::HEWindow::Update()
{
}
