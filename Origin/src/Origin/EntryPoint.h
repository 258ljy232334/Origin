#pragma once
#ifdef OG_PLATFORM_WINDOWS

extern Origin::Application* Origin::CreateApplication();
int main(int argc,char** argv)
{
	auto app = Origin::CreateApplication();
	app->Run();
	delete app;
}
#endif // OG_PLATFORM_WINDOWS

