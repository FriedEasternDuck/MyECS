//
// Created by rooster on 05/10/24.
//

#include "../includes/PhysicsSystem.h"
#include "../includes/Scene.h"

void PhysicsSystem::update(Scene &scene, Entity entity) {
        if (scene.hasComponent<PhysicsComponent>(entity)) {
                if (const auto &physicsComponent = scene.getComponent<PhysicsComponent>(entity); physicsComponent.
                        isEffectedByGravity) {
                        auto &positionComponent = scene.getComponent<PositionComponent>(entity);
                        positionComponent.position.y -= GRAVITY;
                }
        }
}
