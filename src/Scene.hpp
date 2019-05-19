#pragma once

#include "scene/Node.hpp"

class Engine;

class Scene : public Node {
public:
	virtual ~Scene() = default;

	virtual void attachEngine(Engine* engine) { _engine = engine; }
	virtual void onCreated() = 0;
	virtual void update(float delta) = 0;
	virtual void onDestroy() = 0;

protected:
	Engine* _engine = nullptr;
};