#pragma once
#ifndef __I_UPDATABLE_HPP__
#define __I_UPDATABLE_HPP__
namespace Gamengi
{
	class IUpdatable
	{
	public:
		virtual ~IUpdatable() {}

		virtual void Update(float dt) = 0;
		virtual void Reset() = 0;
	};
}
#endif // __I_UPDATABLE_HPP__