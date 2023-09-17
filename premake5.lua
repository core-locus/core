workspace "Cacus"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include Directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "src/vendor/GLFW/include"

include "src/vendor/GLFW"

project "Cacus"
    location "src"
    kind "SharedLib"
    language "C++"
    cppdialect "C++11"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "ccspch.h"
    pchsource "src/%{prj.name}/ccspch.cpp"

    files
    {
        "src/%{prj.name}/**.h",
        "src/%{prj.name}/**.cpp",
        "src/Platform/**.h",
        "src/Platform/**.cpp"
    }

    includedirs
    {
        "src",
        "src/%{prj.name}",
        "src/vendor/spdlog/include",
        "%{IncludeDir.GLFW}"
    }
    
    links 
    {
        "GLFW",
        "OpenGL.framework",
        "Cocoa.framework",
        "IOKit.framework",
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "CCS_PLATFORM_WINDOWS",
            "CCS_BUILD_DLL"
        }

        links
        {
            "opengl32.lib"
        }

    filter "system:macos"
        staticruntime "On"
        systemversion "latest"

    filter "configurations:Debug"
        defines "CCS_DEBUG"
        -- buildoptions "/MDd"
        symbols "On"

    filter "configurations:Release"
        defines "CCS_RELEASE"
        -- buildoptions "/MD"
        optimize "On"

    filter "configurations:Dist"
        defines "CCS_DIST"
        -- buildoptions "/MD"
        optimize "On"

project "Sandbox"
    location "examples/%{prj.name}"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "ccspch.h"
    pchsource "src/Cacus/ccspch.cpp"

    files
    {
        "examples/%{prj.name}/src/**.h",
        "examples/%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "src/vendor/spdlog/include",
        "src"
    }

    links
    {
        "Cacus"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "CCS_PLATFORM_WINDOWS"
        }

    filter "system:macos"
        staticruntime "On"
        systemversion "latest"

    filter "configurations:Debug"
        defines "CCS_DEBUG"
        -- buildoptions "/MDd"
        symbols "On"

    filter "configurations:Release"
        defines "CCS_RELEASE"
        -- buildoptions "/MD"
        optimize "On"

    filter "configurations:Dist"
        defines "CCS_DIST"
        -- buildoptions "/MD"
        optimize "On"