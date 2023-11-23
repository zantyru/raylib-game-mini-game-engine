#pragma once
#ifndef __LIBRARY_HPP__
#define __LIBRARY_HPP__


#include <array>


namespace Gamengi
{
	template<typename T, std::size_t SIZE>
	class Library
	{
	public:
		virtual void Load() = 0;
		virtual void Unload() = 0;
		// virtual void Render() Use() Get()???

	protected:
		std::array<T, SIZE> _items;

	private:
		//...
	};
}
#endif // __LIBRARY_HPP__