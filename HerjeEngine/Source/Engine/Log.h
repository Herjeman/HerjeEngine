#pragma once
#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"


namespace HerjeEngine {

	class HE_API Log
	{
	public:
		static void Initialize();

		inline static std::shared_ptr<spdlog::logger>& GetEngineLogger() { return s_EngineLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetGameLogger() { return s_GameLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_EngineLogger;
		static std::shared_ptr<spdlog::logger> s_GameLogger;
	};
}

#define HE_LOG_CORE_TRACE(...)    HerjeEngine::Log::GetEngineLogger()->trace(__VA_ARGS__)
#define HE_LOG_CORE_INFO(...)     HerjeEngine::Log::GetEngineLogger()->info(__VA_ARGS__)
#define HE_LOG_CORE_WARN(...)     HerjeEngine::Log::GetEngineLogger()->warn(__VA_ARGS__)
#define HE_LOG_CORE_ERROR(...)    HerjeEngine::Log::GetEngineLogger()->error(__VA_ARGS__)
#define HE_LOG_CORE_CRITICAL(...) HerjeEngine::Log::GetEngineLogger()->critical(__VA_ARGS__)

#define HE_LOG_TRACE(...)         HerjeEngine::Log::GetGameLogger()->trace(__VA_ARGS__)
#define HE_LOG_INFO(...)          HerjeEngine::Log::GetGameLogger()->info(__VA_ARGS__)
#define HE_LOG_WARN(...)          HerjeEngine::Log::GetGameLogger()->warn(__VA_ARGS__)
#define HE_LOG_ERROR(...)         HerjeEngine::Log::GetGameLogger()->error(__VA_ARGS__)
#define HE_LOG_CRITICAL(...)      HerjeEngine::Log::GetGameLogger()->critical(__VA_ARGS__)

#ifdef HE_CONFIGURATION_RELEASE
	#define HE_LOG_CORE_TRACE  
	#define HE_LOG_CORE_INFO
	#define HE_LOG_CORE_WARN
	#define HE_LOG_CORE_ERROR
	#define HE_LOG_CORE_CRITICAL

	#define HE_LOG_TRACE   
	#define HE_LOG_INFO
	#define HE_LOG_WARN      
	#define HE_LOG_ERROR
	#define HE_LOG_CRITICAL
#endif // HE_RELEASE
