//
// Created by rooster on 05/10/24.
//

#include "../includes/PhysicsSystem.h"
#include "../includes/Scene.h"

void PhysicsSystem::update(Scene &scene) {
        for (const auto e: scene.entities()) {
                if (scene.hasComponent<PhysicsComponent>(e)) {
                        if (const auto &physicsComponent = scene.getComponent<PhysicsComponent>(e); physicsComponent.isEffectedByGravity) {
                                auto &positionComponent = scene.getComponent<PositionComponent>(e);
                                positionComponent.position.y -= GRAVITY;
                        }
                }
        }
}
