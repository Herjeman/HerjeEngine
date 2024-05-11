#pragma once

#ifdef HE_PLATFORM_WINDOWS
	#ifdef HE_BUILD_DLL
		#define HE_API __declspec(dllexport)
	#else
		#define HE_API __declspec(dllimport)
	#endif
#else
	#error HerjeEngine only supports Windows!
#endif