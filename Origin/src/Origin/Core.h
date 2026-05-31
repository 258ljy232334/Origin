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

