#pragma once

#include <vector>

#include "math/Vector3.h"

#include "ECS.h"

struct TransformComponent {
	Vector3 position;
};

struct TransformWrapper {
	TransformComponent component;
    LocalHandle nextComponentHandle;
    ComponentStatus status;
};

namespace transform_system_globals {
    static const GlobalHandle k_transformHandlePrefix = 0x00010000;
    static TransformComponent g_invalidTransformComponent = TransformComponent();
}

class TransformSystem {
public:
    std::vector<TransformWrapper> _components;
    LocalHandle _nextComponentHandle;

	TransformSystem() = default;
	TransformSystem(const TransformSystem&& rhs) = delete;
	TransformSystem(TransformSystem&& rhs) = delete;
	TransformSystem& operator=(const TransformSystem& rhs) = delete;
	TransformSystem& operator=(const TransformSystem&& rhs) = delete;

    void initWithCapacity(int16_t capacity);
    GlobalHandle create();
	GlobalHandle create(const Vector3& position);
    void destroy(GlobalHandle globalHandle);
    TransformComponent& get(GlobalHandle globalHandle);
};
