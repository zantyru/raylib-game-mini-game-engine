#include "GameObject.hpp"
#include "SceneLayer.hpp"


namespace Gamengi
{
	SceneLayer::SceneLayer()
	{
		//Nothing
	}

	SceneLayer::~SceneLayer()
	{
		//...
	}

	void SceneLayer::Add(GameObject::Ptr p_gameObject)
	{
		_sceneLayerDeferredAdd.push(p_gameObject);
	}

	void SceneLayer::Remove(GameObject::ID gameObjectID)
	{
		_sceneLayerDeferredRemove.push(gameObjectID);
	}

	void SceneLayer::Remove(GameObject::Ptr p_gameObject)
	{
		Remove(p_gameObject->GetID());
	}

	void SceneLayer::Draw()
	{
		_ResolveDeferredObjects();
		//...
	}

	void SceneLayer::Update(float dt)
	{
		_ResolveDeferredObjects();
		//...
	}

	void SceneLayer::Reset()
	{
		_ResolveDeferredObjects();
		//...
	}

	void SceneLayer::_ResolveDeferredObjects()
	{
		GameObject::Ptr p_gameObject{};
		GameObject::ID gameObjectID{};

		// Добавление объектов из очереди на слой сцены
		while (_sceneLayerDeferredAdd.size() > 0)
		{
			p_gameObject = _sceneLayerDeferredAdd.front();
			_sceneLayerDeferredAdd.pop();

			gameObjectID = p_gameObject->GetID();
			_gameObjects.insert({ gameObjectID, p_gameObject });
			p_gameObject->RememberParentSceneLayer(std::make_shared<SceneLayer>(this));

			IUpdatable::Ptr p_updgo{};
			p_updgo = std::dynamic_pointer_cast<IUpdatable::Ptr>(p_gameObject);
			if (p_updgo != nullptr) _updatables.insert({ gameObjectID, p_updgo });

			IDrawable::Ptr p_drwgo{};
			p_drwgo = std::dynamic_pointer_cast<IDrawable::Ptr>(p_gameObject);
			if (p_drwgo != nullptr) _drawables.insert({ gameObjectID, p_drwgo });

			//ICollidable::Ptr p_cldgo{};
			//p_cldgo = std::dynamic_pointer_cast<ICollidable::Ptr>(p_gameObject);
			//if (p_cldgo != nullptr) _collidable.insert({ gameObjectID, p_cldgo });
		}

		// Удаление объектов из слоя сцены, которые находятся
		// в очереди на удаление
		while (_sceneLayerDeferredRemove.size() > 0)
		{
			gameObjectID = _sceneLayerDeferredRemove.front();
			_sceneLayerDeferredRemove.pop();

			if (_gameObjects.erase(gameObjectID) > 0)
			{
				_updatables.erase(gameObjectID);
				_drawables.erase(gameObjectID);
				//_collidable.erase(gameObjectID);
			}
		}
	}
}