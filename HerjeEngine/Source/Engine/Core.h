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

#ifdef HE_ENABLE_ASSERTS
	#define HE_CORE_ASSERT(x, ...) if(!x){ HE_LOG_CORE_ERROR(__VA_ARGS__); __debugbreak();}
	#define HE_ASSERT(x, ...) if(!x){ HE_LOG_ERROR(__VA_ARGS__); __debugbreak();}
#else
	#define HE_CORE_ASSERT(x, ...)
	#define HE_ASSERT(x, ...)
#endif // HE_ENABLE_ASSERTS
