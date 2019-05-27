#include "Node.hpp"

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
