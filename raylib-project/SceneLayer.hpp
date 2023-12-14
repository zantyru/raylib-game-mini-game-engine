#pragma once
#ifndef __SCENE_LAYER_HPP__
#define __SCENE_LAYER_HPP__


#include <memory>
#include <map>
#include "IUpdatable.hpp"
#include "IDrawable.hpp"


namespace Gamengi
{
	class SceneLayer : public IUpdatable, public IDrawable
	{
	public:
		using Ptr = std::shared_ptr<SceneLayer>;

	protected:
		//...

	private:
		//...
	};
}
#endif // __SCENE_LAYER_HPP__