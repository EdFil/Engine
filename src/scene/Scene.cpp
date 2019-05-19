#include "scene/Scene.hpp"

void Scene::update(float delta) {
	for (Node* node : _children) {
		node->update(delta);
	}
}
