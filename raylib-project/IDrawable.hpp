#pragma once
#ifndef __I_DRAWABLE_HPP__
#define __I_DRAWABLE_HPP__


#include <memory>


namespace Gamengi
{
	class IDrawable
	{
	public:
		using Ptr = std::shared_ptr<IDrawable>;

		virtual ~IDrawable() {}

		virtual void Draw() = 0;
	};
}
#endif // __I_DRAWABLE_HPP__