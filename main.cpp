#include <iostream>

#include "Code/includes/Components.h"
#include "Code/includes/PhysicsSystem.h"
#include "Code/includes/Scene.h"

int main() {
        auto scene = std::make_shared<Scene>();
        auto physicsSystem = std::make_unique<PhysicsSystem>();
        scene->addSystem(std::move(physicsSystem));
        auto player = scene->createEntity();
        std::vector<Entity> testEntities;

        PhysicsComponent physics_component(true);
        PositionComponent position_component;
        scene->addComponent<PhysicsComponent>(player, physics_component);
        scene->addComponent<PositionComponent>(player, position_component);
        scene->getComponent<PositionComponent>(player).position += glm::vec3(06, 40, 03);

        PositionComponent testPC{glm::vec3(06,40,93)};

        const auto entitiyFromComponent = scene->getEntityFromComponent(testPC);

        printf("Entity from comp: %d", entitiyFromComponent);


        return 0;
}
