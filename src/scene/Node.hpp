#pragma once

#include <vector>

#include "ecs/ECS.hpp"

class Node {
public:
	void addComponentHandle(GlobalHandle globalHandle);
	void removeComponentHandle(GlobalHandle globalHandle);

protected:
	std::vector<GlobalHandle> _componentHandles;
};
