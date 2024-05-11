#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace HerjeEngine
{
	std::shared_ptr<spdlog::logger> Log::s_EngineLogger;
	std::shared_ptr<spdlog::logger> Log::s_GameLogger;

	void Log::Initialize()
	{
		s_EngineLogger = spdlog::stdout_color_mt("HerjeEngine");
		s_EngineLogger->set_level(spdlog::level::trace);

		s_GameLogger = spdlog::stdout_color_mt("Game");
		s_GameLogger->set_level(spdlog::level::trace);
	}
}
