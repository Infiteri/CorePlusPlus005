// typedef

// Const char definition
typedef const char String;
typedef unsigned int Uint;

#ifdef CORE_WINDOWS_PLATFORM

// Define __declspec(dllexport)
#ifdef CORE_BUILD_DLL
#define CORE_API __declspec(dllexport)
#else
#define CORE_API __declspec(dllimport)
#endif

#else
#error Core is only windows !
#endif