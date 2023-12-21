#pragma once
#ifndef __I_UPDATABLE_HPP__
#define __I_UPDATABLE_HPP__


#include <memory>


namespace Gamengi
{
	class IUpdatable
	{
	public:
		using Ptr = std::shared_ptr<IUpdatable>;

		virtual ~IUpdatable() {}

		virtual void Update(float dt) = 0;
		virtual void Reset() = 0;
	};
}
#endif // __I_UPDATABLE_HPP__