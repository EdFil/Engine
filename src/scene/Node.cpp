//
// Created by edgar on 5/19/19.
//

#include "Node.hpp"

#include <algorithm>

Node::~Node() {

}

const Vector3& Node::position() const {
	return _relativePosition;
}

void Node::setPosition(float x, float y, float z) {
	_relativePosition.x = x;
	_relativePosition.y = y;
	_relativePosition.z = z;
}

void Node::setPosition(const Vector3& position) {
	_relativePosition = position;
}

// *************** Scene Graph Stuff ***************

void Node::addChild(Node* node) {
	const std::pair<std::set<Node*>::iterator, bool> result =_children.insert(node);
    if (result.second) {
        node->_parent = this;
    }
}

void Node::removeChild(Node *node) {
	removeChild(node, true);
}

void Node::removeChild(Node* node, bool shouldDelete) {
	_children.erase(node);
	node->_parent = nullptr;

	if (shouldDelete) {
		delete node;
	}
}

void Node::removeAllChildren() {
    removeAllChildren(true);
}

void Node::removeAllChildren(bool shouldDeleteChildren) {
}

void Node::update(float delta) {

}

// *************** ECS Stuff ***************

void Node::addComponentHandle(GlobalHandle globalHandle) {
	_componentHandles.push_back(globalHandle);
}

void Node::removeComponentHandle(GlobalHandle globalHandle) {
	for (size_t i = 0; i < _componentHandles.size(); i++) {
		if (_componentHandles[i] == globalHandle) {
			_componentHandles[i] = _componentHandles.back();
			_componentHandles.pop_back();
			return;
		}
	}
}
