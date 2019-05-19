//
// Created by edgar on 5/19/19.
//

#include "Node.hpp"

#include <algorithm>

Node::~Node() {

}

void Node::addChild(Node* node) {
    std::pair<std::set<Node*>::iterator, bool> result =_children.insert(node);
    if (result.second) {
        node->_parent = this;
    }
}

void Node::removeChild(Node *node) {
    _children.erase(node);
}

void Node::removeAllChildren() {
    removeAllChildren(true);
}

void Node::removeAllChildren(bool shouldDeleteChildren) {
    for ()
}

void Node::update() {

}
