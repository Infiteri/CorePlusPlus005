#include "Logger.h"
#include <windows.h>
#include "stdio.h"

namespace Core
{

    void Logger::Log(Logger::LogLevel level, String *message, ...)
    {

        HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
        String *levels[4] = {"INFO", "WARN", "ERROR", "FATAL"};

        switch (level)
        {
        case LogLevel::LOG_INFO:
            SetConsoleTextAttribute(h, 15);
            break;

        case LogLevel::LOG_WARN:
            SetConsoleTextAttribute(h, 14);
            break;

        case LogLevel::LOG_ERROR:
            SetConsoleTextAttribute(h, 4);
            break;

        case LogLevel::LOG_FATAL:
            SetConsoleTextAttribute(h, 832);
            break;
        }

        char out_message[32000];
        memset(out_message, 0, sizeof(out_message));

        // Format original message.
        // NOTE: Oddly enough, MS's headers override the GCC/Clang va_list type with a "typedef char* va_list" in some
        // cases, and as a result throws a strange error here. The workaround for now is to just use __builtin_va_list,
        // which is the type GCC/Clang's va_start expects.
        __builtin_va_list arg_ptr;
        va_start(arg_ptr, message);
        vsnprintf(out_message, 32000, message, arg_ptr);
        va_end(arg_ptr);

        printf("[LOG %s]: %s \n", levels[level], out_message);
    }

}
