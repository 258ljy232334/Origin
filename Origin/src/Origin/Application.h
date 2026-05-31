#pragma once
#include "Core.h"
namespace Origin
{
	class ORIGIN_API Application
	{
		public:
		Application();
		virtual ~Application();
		
		void Run();
	};
	Application* CreateApplication();
}

