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

	files
	{
		"%{prj.name}/Source/**.h",
		"%{prj.name}/Source/**.cpp"
	}

	includedirs
	{
		"%{prj.location}/ThirdParty/Spdlog/include"
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

	filter "configurations:Debug"
		defines "HE_CONFIGURATION_DEBUG"
		symbols "On"

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
		"HerjeEngine/Source"
	}

	links
	{
		"HerjeEngine"
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