#pragma once

#include <cinttypes>
#include <set>

#include "math/Vector3.h"

class Node {
public:

    ~Node();

    void setPosition(float x, float y, float z)

    void addChild(Node* node);
    void removeChild(Node* node);
    void removeAllChildren();
    void removeAllChildren(bool shouldDeleteChildren);

    void update();

private:
    Vector3 _relativePosition;
    float _rotation;
    int32_t _zOrder;

    std::set<Node*> _children;
    Node* _parent;
};
