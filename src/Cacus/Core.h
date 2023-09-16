#pragma once

#ifdef _WIN32
    #ifdef CCS_BUILD_DLL
        #define CACUS_API __declspec(dllexport)
    #else
        #define CACUS_API __declspec(dllimport)
    #endif
#else
    #define CACUS_API
#endif

#ifdef CCS_ENABLE_ASSERTS
    #define CCS_ASSERT(x, ...) { if (!(x)) { CCS_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
    #define CCS_CORE_ASSERT(x, ...) { if (!(x)) { CCS_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
    #define CCS_ASSERT(x, ...)
    #define CCS_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)