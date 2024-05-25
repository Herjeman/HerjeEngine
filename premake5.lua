workspace "HerjeEngine"

	architecture "x64"
	configurations
	{
		"Debug",
		"Release"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "HerjeEngine"
	location "HerjeEngine"
	kind "SharedLib"
	language "C++"

	targetdir ("Binaries/" .. outputdir .. "/%{prj.name}")
	objdir ("Binaries_Intermediaries/" .. outputdir .. "/%{prj.name}")

	pchheader "HEPreCompiled.h"
	pchsource "%{prj.name}/Source/HEPreCompiled.cpp"

	files
	{
		"%{prj.name}/Source/**.h",
		"%{prj.name}/Source/**.cpp"
	}

	includedirs
	{
		"%{prj.location}/Source",
		"%{prj.location}/ThirdParty/Spdlog/include",
		"%{prj.location}/ThirdParty/SDL/include"
	}

	libdirs
	{
		"%{prj.location}/ThirdParty/SDL/VisualC/x64/%{cfg.buildcfg}/SDL3.lib"
	}
	links
	{
		"%{prj.location}/ThirdParty/SDL/VisualC/x64/%{cfg.buildcfg}/SDL3.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"HE_PLATFORM_WINDOWS",
			"HE_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../Binaries/" ..outputdir.. "/Game")
		}

	filter "configurations:Release"
		defines "HE_CONFIGURATION_RELEASE"
		optimize "On"
		buildoptions "/MD"

	filter "configurations:Debug"
		defines "HE_CONFIGURATION_DEBUG"
		symbols "On"
		buildoptions "/MDd"

project "Game"
	location "Game"
	kind "ConsoleApp"
	language "C++"

	targetdir ("Binaries/" .. outputdir .. "/%{prj.name}")
	objdir ("Binaries_Intermediaries/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/Source/**.h",
		"%{prj.name}/Source/**.cpp"
	}

	includedirs
	{
		"%{wks.location}/HerjeEngine/ThirdParty/Spdlog/include",
		"HerjeEngine/Source",
		"%{wks.location}/HerjeEngine/ThirdParty/SDL/include"
	}

	libdirs
	{
		"%{wks.location}/HerjeEngine/ThirdParty/SDL/VisualC/x64/%{cfg.buildcfg}/SDL3.lib"
	}

	links
	{
		"HerjeEngine",
		"%{wks.location}/HerjeEngine/ThirdParty/SDL/VisualC/x64/%{cfg.buildcfg}/SDL3.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"HE_PLATFORM_WINDOWS"
		}

	filter "configurations:Release"
		defines "HE_CONFIGURATION_RELEASE"
		optimize "On"

	filter "configurations:Debug"
		defines "HE_CONFIGURATION_DEBUG"
		symbols "On"