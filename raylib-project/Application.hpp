#pragma once
#ifndef __APPLICATION_HPP__
#define __APPLICATION_HPP__
namespace Gamengi
{
	template<class T>
	class Application
	{
	public:
		Application(const Application& other) = delete;
		Application& operator=(const Application& other) = delete;
		
		static T& GetInstance();
		void Run();

	protected:
		struct _Token {};

		Application();

		virtual void AcquireResources();
		virtual void StartMainLoop();
		virtual void ReleaseResources();
	};
}
#endif // __APPLICATION_HPP__