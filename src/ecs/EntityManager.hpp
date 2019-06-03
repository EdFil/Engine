#pragma once

#include "ECS.hpp"

#include <vector>

#include "container/ObjectPool.hpp"

namespace entity_system_globals {
    static const SystemIndex k_entitySystemIndex = 1 << (32 - k_numBitsIndex);
}

struct Entity {
    GlobalHandle handle;
};

class EntityManager {
public:
    ObjectPool<Entity> _entities;

    EntityManager() = default;
    EntityManager(const EntityManager&& rhs) = delete;
    EntityManager(EntityManager&& rhs) = delete;
    EntityManager& operator=(const EntityManager& rhs) = delete;
    EntityManager& operator=(const EntityManager&& rhs) = delete;

    bool initWithCapacity(uint32_t capacity);
    GlobalHandle createEntity();
    void releaseEntity(const GlobalHandle handle);
};
