#pragma once
#ifndef __GAME_OBJECT_HPP__
#define __GAME_OBJECT_HPP__


#include <queue>
#include "SceneLayer.hpp"


namespace Gamengi
{
	class GameObject
	{
	public:
		using ID = size_t;

		ID              GetID() const;
		SceneLayer::Ptr GetParentSceneLayer() const;
		void            RememberParentSceneLayer(SceneLayer::Ptr p_sceneLayer);

	protected:
		GameObject();
		~GameObject();

	private:
		static ID             _nextBiggestID;
		static std::queue<ID> _prevDisposedIDs;
		ID                    _id;
		SceneLayer::Ptr       _p_parentScene;
	};
}
#endif // __GAME_OBJECT_HPP__