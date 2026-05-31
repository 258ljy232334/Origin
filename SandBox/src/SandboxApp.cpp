#include <Origin.h>

class Sandbox:public Origin::Application
{
public:
	Sandbox() 
	{
	
	}
	~Sandbox() 
	{
	
	}
};
Origin::Application* Origin::CreateApplication()
{
	return new Sandbox();
}