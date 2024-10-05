//
// Created by rooster on 04/10/24.
//

#include "../includes/EntityManager.h"

#include <cstdlib>
#include <stdexcept>

EntityManager::Entity EntityManager::MAX_ENTITIES = std::numeric_limits<Entity>::max();
EntityManager::Entity EntityManager::NEXT_ENTITY_ID = 1;

EntityManager::Entity EntityManager::createEntity() {
        if (!freeEntities.empty()) {
                const auto entity = freeEntities.back();
                freeEntities.pop_back();
                return entity;
        }
        if (NEXT_ENTITY_ID <= MAX_ENTITIES) {
                return NEXT_ENTITY_ID++;
        }
        throw std::invalid_argument("EntityManager::createEntity: Entity Limit Reached");
}

void EntityManager::freeEntity(const Entity entity) {
        freeEntities.push_back(entity);
}
