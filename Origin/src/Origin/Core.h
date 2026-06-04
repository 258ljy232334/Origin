#pragma once

#ifdef OG_PLATFORM_WINDOWS
	#ifdef OG_BUILD_DLL
		#define ORIGIN_API __declspec(dllexport)
	#else
		#define ORIGIN_API __declspec(dllimport)
	#endif 
#else
	#error Origin only supports Windows!
#endif // OG_PLATFORM_WINDOWS

#ifdef OG_ENABLE_ASSERTS
#define OG_ASSERT(x, ...) { if(!(x)) { OG_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#define OG_CORE_ASSERT(x, ...) { if(!(x)) { OG_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
#define OG_ASSERT(x, ...)
#define OG_CORE_ASSERT(x, ...)
#endif // OG_ENABLE_ASSERTS


#define BIT(x) (1<<x)



