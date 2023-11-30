#pragma once
#ifndef __APPLICATION_HPP__
#define __APPLICATION_HPP__
namespace Gamengi
{
	class Application
	{
	public:
		Application(const Application& other) = delete;
		Application& operator=(const Application& other) = delete;
		virtual ~Application();
		
		void Run();

	protected:
		Application();

		virtual void AcquireResources() = 0;
		virtual void StartMainLoop() = 0;
		virtual void ReleaseResources() = 0;
	};
}
#endif // __APPLICATION_HPP__