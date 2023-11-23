#pragma once
#ifndef __NODE_HPP__
#define __NODE_HPP__


#include <vector>
#include "raylib.h"


namespace Gamengi
{
	class Node
	{
	public:
		using Index = std::vector<Node*>::size_type;
		using ChildCount = std::vector<Node*>::size_type;

		Node();
		Node(const Node& other) = delete;
		Node& operator=(const Node& other) = delete;
		~Node();

		Index AddNode(const Node& node);
		bool RemoveNode(Index index);
		Node& PeekNode(Index index);
		bool TryFindNode(const Node& node, const Index& index);
		ChildCount GetChildCount();

		Node& PeekParent();

		//@TODO реализовать индексатор []
		//@TODO клонирование (возможно, ICloneable)

	protected:
	private:
		Node* _pParent;
		std::vector<Node*> _childrenPointers;
	};
}
#endif // __NODE_HPP__