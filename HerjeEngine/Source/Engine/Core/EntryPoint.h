#pragma once
#include "Application.h"

#ifdef HE_PLATFORM_WINDOWS

extern HerjeEngine::Application* HerjeEngine::CreateApplication();

struct SomeEvent {
	int Num = 42;
	SomeEvent() {}
	SomeEvent(int num) : Num(num) {}
};

struct SomeOtherEvent {
	std::string Str = "Foo";

	SomeOtherEvent() {};
	SomeOtherEvent(std::string str) : Str(str) {}
};


int main(int argc, char** argv)
{
	HerjeEngine::Log::Initialize();
	HE_LOG_CORE_INFO("Welcome to HerjeEngine");

	auto application = HerjeEngine::CreateApplication();
	application->Run();
	delete application;

	HE_LOG_CORE_INFO("Thank you for using HerjeEngine");
}


#endif // HE_PLATFORM_WINDOWS
