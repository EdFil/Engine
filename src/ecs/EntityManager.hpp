#pragma once

#include "ECS.hpp"

#include <vector>

struct Entity {
    uint32_t id;
};

struct EntityWrapper {
    Entity entity;
    LocalHandle nextEntityHandle;
    ComponentStatus status;
};

class EntityManager {
public:
    std::vector<EntityWrapper> _entities;
    LocalHandle _nextComponentHandle;

    EntityManager() = default;
    EntityManager(const TransformSystem&& rhs) = delete;
    EntityManager(TransformSystem&& rhs) = delete;
    EntityManager& operator=(const EntityManager& rhs) = delete;
    EntityManager& operator=(const EntityManager&& rhs) = delete;

    void initWithCapacity(int16_t capacity);
    GlobalHandle create();
    void destroy(GlobalHandle globalHandle);
    Entity* get(GlobalHandle globalHandle);
};
