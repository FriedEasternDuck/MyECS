//
// Created by rooster on 04/10/24.
//

#ifndef SCENE_H
#define SCENE_H
#include <vector>
#include <cstdint>
#include <memory>
#include "ComponentPool.h"
#include "EntityManager.h"
#include "SystemBase.h"

using Entity = std::uint32_t;

class EntityManager;
class PositionComponent;
class VelocityComponent;
class PhysicsComponent;

class Scene {
private:
        EntityManager entityManager;

        std::vector<Entity> _entities;
        ComponentPool<PositionComponent> _positionPool;
        ComponentPool<VelocityComponent> _velocityPool;
        ComponentPool<PhysicsComponent> _physicsPool;

        std::vector<std::unique_ptr<SystemBase> > _systems;

        template<typename T>
        [[nodiscard]] ComponentPool<T> &getComponentPool();

public:
        Scene();

        void addSystem(std::unique_ptr<SystemBase> system) {
                _systems.push_back(std::move(system));
        }

        void update() {
                for (auto &system: _systems) {
                        system->update(*this);
                }
        }

        Entity createEntity();

        void freeEntity(Entity entity);

        template
        <
                typename ComponentType, typename Component>

        void addComponent(Entity entity, Component component) {
                auto &pool = getComponentPool<ComponentType>();
                pool.addComponent(entity, component);
        }

        template
        <
                typename ComponentType>

        void removeComponent(Entity entity) {
                auto &pool = getComponentPool<ComponentType>();
                pool.removeComponent(entity);
        }

        template
        <
                typename ComponentType>
        ComponentType &getComponent(Entity entity) {
                auto &pool = getComponentPool<ComponentType>();
                return pool.getComponent(entity);
        }

        template
        <
                typename ComponentType>

        bool hasComponent(Entity entity) {
                auto &pool = getComponentPool<ComponentType>();
                return pool.hasComponent(entity);
        }

        [[nodiscard]] const std::vector<Entity> &entities() const {
                return _entities;
        }

        [[nodiscard]] const ComponentPool<PositionComponent> &position_pool() const {
                return _positionPool;
        }

        [[nodiscard]] const ComponentPool<VelocityComponent> &velocity_pool() const {
                return _velocityPool;
        }

        [[nodiscard]] const ComponentPool<PhysicsComponent> &physics_pool() const {
                return _physicsPool;
        }
};

template<>
inline ComponentPool<PositionComponent> &Scene::getComponentPool() {
        return _positionPool;
}

template<>
inline ComponentPool<VelocityComponent> &Scene::getComponentPool() {
        return _velocityPool;
}

template<typename T>
ComponentPool<T> &Scene::getComponentPool() {
        return _physicsPool;
}


#endif //SCENE_H
