#pragma once

#include "scene/Node.hpp"

class Engine;

class Scene {
public:
	virtual ~Scene() = default;

	void attachEngine(Engine* engine) { _engine = engine; }
	virtual void onCreated() {}
	virtual void onDestroy() {}

protected:
	Engine* _engine = nullptr;
};