#pragma once

#include <cinttypes>
#include <set>

#include "math/Vector3.h"
#include "ecs/ECS.h"
#include <vector>

class Node {
public:

	virtual ~Node();

	const Vector3& position() const;
	void setPosition(float x, float y, float z);
	void setPosition(const Vector3& position);

    void addChild(Node* node);
    void removeChild(Node* node);
	void removeChild(Node* node, bool shouldDelete);
    void removeAllChildren();
    void removeAllChildren(bool shouldDeleteChildren);

	virtual void update(float delta);

	void addComponentHandle(GlobalHandle globalHandle);
	void removeComponentHandle(GlobalHandle globalHandle);


protected:
	// Node stuff
    Vector3 _relativePosition;
    float _rotation = 0.0f;
    int32_t _zOrder = 0;

	// SceneGraph stuff
    std::set<Node*> _children;
    Node* _parent = nullptr;

	// ECS stuff
	std::vector<GlobalHandle> _componentHandles;
};
