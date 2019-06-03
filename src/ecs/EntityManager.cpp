#include "EntityManager.hpp"

#include <SDL_log.h>

bool EntityManager::initWithCapacity(uint32_t capacity) {
    if (capacity > k_localIndex) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[EntityManager::initWithCapacity]  Trying to create %d out of a max of %d. Clamping...", capacity, k_localIndex);
        capacity = capacity & k_invalidHandle;
    }

    return _entities.initWithSize(capacity);
}

GlobalHandle EntityManager::createEntity() {
    return _entities.getNewHandle() | entity_system_globals::k_entitySystemIndex;
}

void EntityManager::releaseEntity(const GlobalHandle handle) {
    _entities.releaseHandle(handle);
}
