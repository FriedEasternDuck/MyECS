//
// Created by rooster on 04/10/24.
//

#ifndef COMPONENTPOOL_H
#define COMPONENTPOOL_H
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <cstdint>
#include <stdexcept>

#include "EntityManager.h"

template<typename T>
class ComponentPool {
private:
        using Entity = std::uint32_t;

        std::vector<T> components;
        std::unordered_map<Entity, size_t> entityToIndex; // Maps entity to component index
        std::unordered_map<size_t, Entity> indexToEntity; // Maps component index to entity
public:
        void addComponent(Entity entity, T component);

        void removeComponent(Entity entity);

        T &getComponent(Entity entity);

        Entity getEntity(T &component);

        bool hasComponent(const Entity entity) const {
                return entityToIndex.contains(entity);
        }
};

template<typename T>
void ComponentPool<T>::addComponent(const Entity entity, T component) {
        components.push_back(component);
        const std::size_t index = components.size() - 1;
        entityToIndex[entity] = index;
        indexToEntity[index] = entity;
}


template<typename T>
void ComponentPool<T>::removeComponent(const Entity entity) {
        // Step 1: Get the index of the component to be removed
        size_t indexToRemove = entityToIndex[entity];
        if(!indexToRemove) {
                return;
        }

        // Step 2: Get the last component's index
        size_t lastIndex = components.size() - 1;

        // Step 3: Swap the component to be removed with the last component
        std::swap(components[indexToRemove], components[lastIndex]);

        // Get the entity of the last component
        const Entity lastEntity = indexToEntity[lastIndex];

        // Update the index of the swapped component (originally the last one)
        entityToIndex[lastEntity] = indexToRemove;
        indexToEntity[indexToRemove] = lastEntity;

        // Step 4: Remove the mapping of the removed component's entity
        entityToIndex.erase(entity);
        indexToEntity.erase(lastIndex);

        // Step 5: Remove the last element (which is the component to be removed)
        components.pop_back();
}

template<typename T>
T &ComponentPool<T>::getComponent(Entity entity) {
        auto it = entityToIndex.find(entity);
        if(it == entityToIndex.end()) {
                throw std::out_of_range("Entity does not exist");
        }
        return components[entityToIndex[entity]];
}

template<typename T>
typename ComponentPool<T>::Entity ComponentPool<T>::getEntity(T &component) {
        auto it = std::find(components.begin(), components.end(), component); // Corrected line
        if(it != components.end()) {
                return indexToEntity[std::distance(components.begin(), it)];
        }
        printf("Component not registered to any entity\n");
        return EntityManager::INVALID_ENTITY_ID;
}


#endif //COMPONENTPOOL_H
