#pragma once
#include "Application.h"
#include <stdio.h>

#ifdef HE_PLATFORM_WINDOWS

extern HerjeEngine::Application* HerjeEngine::CreateApplication();

int main(int argc, char** argv)
{
	printf("HerjeEngine");
	auto app = HerjeEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif // HE_PLATFORM_WINDOWS
