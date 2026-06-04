#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Origin
{
	class ORIGIN_API Log
	{
	public:
		//Initializes the logger
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		//Core logger for engine messages
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		//Client logger for application messages
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

//Core log macros
#define OG_CORE_TRACE(...) ::Origin::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define OG_CORE_INFO(...) ::Origin::Log::GetCoreLogger()->info(__VA_ARGS__)
#define OG_CORE_WARN(...) ::Origin::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define OG_CORE_ERROR(...) ::Origin::Log::GetCoreLogger()->error(__VA_ARGS__)
//Client log macros
#define OG_TRACE(...) ::Origin::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define OG_INFO(...) ::Origin::Log::GetClientLogger()->info(__VA_ARGS__)
#define OG_WARN(...) ::Origin::Log::GetClientLogger()->warn(__VA_ARGS__)
#define OG_ERROR(...) ::Origin::Log::GetClientLogger()->error(__VA_ARGS__)