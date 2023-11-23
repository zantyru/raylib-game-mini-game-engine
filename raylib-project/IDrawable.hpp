#pragma once
#ifndef __I_DRAWABLE_HPP__
#define __I_DRAWABLE_HPP__
namespace Gamengi
{
	class IDrawable
	{
	public:
		virtual ~IDrawable() {}

		virtual void Draw() = 0;
	};
}
#endif // __I_DRAWABLE_HPP__