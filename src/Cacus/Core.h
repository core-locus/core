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

#define BIT(x) (1 << x)