#pragma once
#ifndef __SCENE_LAYER_HPP__
#define __SCENE_LAYER_HPP__


#include <memory>
#include <map>
#include <queue>
#include "IUpdatable.hpp"
#include "IDrawable.hpp"
#include "GameObject.hpp"


namespace Gamengi
{
	class SceneLayer : public IUpdatable, public IDrawable
	{
	public:
		using Ptr = std::shared_ptr<SceneLayer>;

		SceneLayer();
		~SceneLayer();

		void Add(GameObject::Ptr);
		void Remove(GameObject::ID);
		void Remove(GameObject::Ptr);

		// IDrawable
		void Draw();

		// IUpdatable
		void Update(float dt);
		void Reset();

	protected:
		//...

	private:
		std::map<GameObject::ID, GameObject::Ptr> _gameObjects;
		std::map<GameObject::ID, IUpdatable::Ptr> _updatables;
		std::map<GameObject::ID, IDrawable::Ptr> _drawables;
		//std::map<GameObject::ID, ICollidable::Ptr> _collidables;

		std::queue<GameObject::Ptr> _sceneLayerDeferredAdd;
		std::queue<GameObject::ID> _sceneLayerDeferredRemove;

		void _ResolveDeferredObjects();
	};
}
#endif // __SCENE_LAYER_HPP__