#include "GameObject.hpp"


namespace Gamengi
{
	static GameObject::ID             _nextBiggestID = 0;
	static std::queue<GameObject::ID> _prevDisposedIDs = std::queue<GameObject::ID>();

	GameObject::GameObject()
		: _id{ 0 }
		, _p_parentScene{ nullptr }
	{
		if (_prevDisposedIDs.size() > 0)
		{
			_id = _prevDisposedIDs.front();
		}
		else
		{
			_id = _nextBiggestID;
			_nextBiggestID++;
		}
	}

	GameObject::~GameObject()
	{
		if (_id == _nextBiggestID - 1)
		{
			_nextBiggestID--;
		}
		else
		{
			_prevDisposedIDs.push(_id);
		}
	}

	GameObject::ID GameObject::GetID() const
	{
		//...
	}

	SceneLayer::Ptr GameObject::GetParentSceneLayer() const
	{
		//...
	}

	void GameObject::RememberParentSceneLayer(SceneLayer::Ptr p_sceneLayer)
	{
		//...
	}
}