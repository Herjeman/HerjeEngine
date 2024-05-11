#pragma once
#include "Application.h"

#ifdef HE_PLATFORM_WINDOWS

extern HerjeEngine::Application* HerjeEngine::CreateApplication();

int main(int argc, char** argv)
{
	HerjeEngine::Log::Initialize();
	HE_LOG_CORE_TRACE("Some text");
	HE_LOG_INFO("Other text");

	auto app = HerjeEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif // HE_PLATFORM_WINDOWS
