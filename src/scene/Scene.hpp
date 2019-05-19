#pragma once

#include "scene/Node.hpp"

class Engine;

class Scene : public Node {
public:
	virtual ~Scene() = default;

	void attachEngine(Engine* engine) { _engine = engine; }
	virtual void onCreated() = 0;
	virtual void onDestroy() = 0;

	void update(float) override;

protected:
	Engine* _engine = nullptr;
};