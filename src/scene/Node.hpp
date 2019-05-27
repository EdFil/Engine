#pragma once

#include <vector>

#include "ecs/ECS.h"

class Node {
public:
	void addComponentHandle(GlobalHandle globalHandle);
	void removeComponentHandle(GlobalHandle globalHandle);

protected:
	std::vector<GlobalHandle> _componentHandles;
};
