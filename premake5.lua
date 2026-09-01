workspace "CppEngine"
    architecture "ARM64"
    configurations { "Release" }
    startproject "CppEngine"

project "CppEngine"
    kind "SharedLib"
    language "C++"
    cppdialect "C++23"

    targetdir "build"
    targetdir "build/obj"

    includedirs
    {
        "include/CppEngine",
        "externals/imgui-sfml",
        "externals/imgui",
        "/opt/homebrew/include/"
    }

    files
    {
        "include/**.hpp",
        "src/**.cpp",
        "externals/**.cpp",
        "externals/**.h"
    }

    links
    {
        "sfml-graphics",
        "sfml-window",
        "sfml-system"
    }

    filter "system:macosx"
        links { "OpenGL.framework" }
        libdirs { "/opt/homebrew/Cellar/sfml/3.0.2/lib" }
