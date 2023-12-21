#pragma once
#ifndef __I_POSITIONABLE_HPP__
#define __I_POSITIONABLE_HPP__


#include <memory>
#include "raylib.h"


namespace Gamengi
{
	class IPositionable2D
	{
	public:
		using Ptr = std::shared_ptr<IPositionable2D>;

		virtual ~IPositionable2D() {}

		virtual void SetPosition(::Vector2 position) = 0;
		virtual ::Vector2 GetPosition() = 0;
		virtual void ChangePosition(::Vector2 transition) = 0;
		virtual void SetRotation(float radians) = 0;
		virtual float GetRotation() = 0;
		virtual void ChangeRotation(float transition) = 0;
	};
}
#endif // __I_POSITIONABLE_HPP__