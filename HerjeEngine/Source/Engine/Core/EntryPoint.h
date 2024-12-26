#pragma once
#include "Engine/Core.h"
#include "Application.h"
#include "Initialization.h"

#ifdef HE_PLATFORM_WINDOWS

extern HerjeEngine::Application* HerjeEngine::CreateApplication();

int main(int argc, char** argv)
{
	HerjeEngine::Log::Initialize();
	HE_LOG_CORE_INFO("Welcome to HerjeEngine");
	HerjeEngine::InitializeDependencies();
	HerjeEngine::InitializeInternal();

	auto application = HerjeEngine::CreateApplication();
	HE_CORE_ASSERT(application, "Application is null");

	application->Run();
	delete application;

	HerjeEngine::ShutDownDependencies();

	HE_LOG_CORE_INFO("Thank you for using HerjeEngine");
}


#endif // HE_PLATFORM_WINDOWS
