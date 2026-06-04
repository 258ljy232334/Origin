workspace "Origin"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}
outputdir= "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir ={}
IncludeDir["GLFW"] = "Origin/vendor/GLFW/include"

include "Origin/vendor/GLFW"

project "Origin"
	location "Origin"
	kind "SharedLib"
	language "C++"
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "ogpch.h"
	pchsource "Origin/src/ogpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}
	links
	{
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		buildoptions "/utf-8"
		defines
		{
			"OG_PLATFORM_WINDOWS",
			"OG_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "OG_DEBUG"
		symbols "On"
	filter "configurations:Release"
		defines "OG_RELEASE"
		symbols "On"
	filter "configurations:Dist"
		defines "OG_DIST"
		symbols "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"

	language "C++"
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	includedirs
	{
		"Origin/src",
		"Origin/vendor/spdlog/include",
	}
	links
	{
		"Origin"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		buildoptions "/utf-8"
		defines
		{
			"OG_PLATFORM_WINDOWS",
		}
	filter "configurations:Debug"
		defines "OG_DEBUG"
		symbols "On"
	filter "configurations:Release"
		defines "OG_RELEASE"
		symbols "On"
	filter "configurations:Dist"
		defines "OG_DIST"
		symbols "On"