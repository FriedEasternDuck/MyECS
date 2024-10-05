#include <iostream>

#include "Code/includes/Components.h"
#include "Code/includes/PhysicsSystem.h"
#include "Code/includes/Scene.h"

int main() {
        auto scene = std::make_shared<Scene>();
        auto physicsSystem = std::make_unique<PhysicsSystem>();
        scene->addSystem(std::move(physicsSystem));
        auto player = scene->createEntity();

        PhysicsComponent physics_component(true);
        PositionComponent position_component;
        scene->addComponent<PhysicsComponent>(player, physics_component);
        scene->addComponent<PositionComponent>(player, position_component);

        int x= 0;
        while (x<10) {

                scene->update();
                printf("Player Pos: %f\n", scene->getComponent<PositionComponent>(player).position.y);

                x++;
        }

        return 0;
}
