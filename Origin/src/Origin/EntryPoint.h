#pragma once
#ifdef OG_PLATFORM_WINDOWS

extern Origin::Application* Origin::CreateApplication();
int main(int argc,char** argv)
{
	auto app = Origin::CreateApplication();
	Origin::Log::Init();
	OG_CORE_ERROR("Hello World");
	OG_TRACE("Not Hello");
	app->Run();
	delete app;
}
#endif // OG_PLATFORM_WINDOWS

