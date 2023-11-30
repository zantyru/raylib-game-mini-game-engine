#include <memory>
#include "Application.hpp"


namespace Gamengi
{
	Application::Application()
	{ }

	Application::~Application()
	{ }

	void Application::Run()
	{
		AcquireResources();
		StartMainLoop();
		ReleaseResources();
	}
}