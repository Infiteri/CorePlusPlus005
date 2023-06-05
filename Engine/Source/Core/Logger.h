#include "EngineCore.h"

namespace Core
{
    class CORE_API Logger
    {

    public:
        Logger();
        ~Logger();

        enum LogLevel
        {
            LOG_INFO,
            LOG_WARN,
            LOG_ERROR,
            LOG_FATAL
        };

        static void Log(Logger::LogLevel level, String *message, ...);
    };
}

// INFO: Macros

#define CORE_INFO(message, ...) Core::Logger::Log(Core::Logger::LogLevel::LOG_INFO, message, ##__VA_ARGS__)
#define CORE_WARN(message, ...) Core::Logger::Log(LCore::ogger::LogLevel::LOG_WARN, message, ##__VA_ARGS__)
#define CORE_ERROR(message, ...) Core::Logger::Log(Core::Logger::LogLevel::LOG_ERROR, message, ##__VA_ARGS__)
#define CORE_FATAL(message, ...) Core::Logger::Log(Core::Logger::LogLevel::LOG_FATAL, message, ##__VA_ARGS__)
