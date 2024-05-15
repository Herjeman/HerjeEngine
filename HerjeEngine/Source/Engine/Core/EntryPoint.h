#pragma once
#include "Application.h"
#include "Initialization.h"

#ifdef HE_PLATFORM_WINDOWS

extern HerjeEngine::Application* HerjeEngine::CreateApplication();

int main(int argc, char** argv)
{
	HerjeEngine::Log::Initialize();
	HE_LOG_CORE_INFO("Welcome to HerjeEngine"); 
	
	HerjeEngine::InitializeDependencies();

	auto application = HerjeEngine::CreateApplication();
	application->Run();
	delete application;

	HerjeEngine::ShutDownDependencies();

	HE_LOG_CORE_INFO("Thank you for using HerjeEngine");
}


#endif // HE_PLATFORM_WINDOWS
