#pragma once

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"

namespace Cacus
{
    class CACUS_API Log
    {
    public: 
        static void Init();

        inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
        inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;
    };
} // namespace Cacus

// Core log macros
#define CCS_CORE_TRACE(...) ::Cacus::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define CCS_CORE_INFO(...)  ::Cacus::Log::GetCoreLogger()->info(__VA_ARGS__)
#define CCS_CORE_WARN(...)  ::Cacus::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define CCS_CORE_ERROR(...) ::Cacus::Log::GetCoreLogger()->error(__VA_ARGS__)
#define CCS_CORE_FATAL(...) ::Cacus::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define CCS_TRACE(...) ::Cacus::Log::GetClientLogger()->trace(__VA_ARGS__)
#define CCS_INFO(...)  ::Cacus::Log::GetClientLogger()->info(__VA_ARGS__)
#define CCS_WARN(...)  ::Cacus::Log::GetClientLogger()->warn(__VA_ARGS__)
#define CCS_ERROR(...) ::Cacus::Log::GetClientLogger()->error(__VA_ARGS__)
#define CCS_FATAL(...) ::Cacus::Log::GetClientLogger()->fatal(__VA_ARGS__)