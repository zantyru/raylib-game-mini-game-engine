#include <memory>
#include "Application.hpp"


namespace Gamengi
{
	template<class T>
	Application<T>::Application()
	{ }

	template<class T>
	T& Application<T>::GetInstance()
	{
		static const std::unique_ptr<T> instance{
			new T{ Application<T>::_Token{} }
		};
		return *instance;
	}
	
	template<class T>
	void Application<T>::Run()
	{
		AcquireResources();
		StartMainLoop();
		ReleaseResources();
	}

	template<class T>
	void Application<T>::AcquireResources()
	{
		throw "Not implemented";
	}

	template<class T>
	void Application<T>::StartMainLoop()
	{
		throw "Not implemented";
	}

	template<class T>
	void Application<T>::ReleaseResources()
	{
		throw "Not implemented";
	}
}