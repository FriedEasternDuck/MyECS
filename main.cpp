#include <iostream>

#include "Code/includes/Components.h"
#include "Code/includes/PhysicsSystem.h"
#include "Code/includes/Scene.h"

int main() {
        auto scene = std::make_unique<Scene>();
        scene->addSystem(std::make_unique<PhysicsSystem>());

        PositionComponent position{glm::vec3(10, 10, 10)};
        PhysicsComponent physics(true);
        int entcnt = 0;
        while (entcnt < 1000000) {
                auto e = scene->createEntity();
                scene->addComponent<PositionComponent>(e, position);
                scene->addComponent<PhysicsComponent>(e, physics);
                entcnt++;
                printf("Entity Count: %d\n", entcnt);
        }

        bool running = true;
        while (running) {
                scene->update();
                printf("Entity Position: %f\n", scene->getComponent<PositionComponent>(100).position.y);
                if (scene->getComponent<PositionComponent>(1000000 - 1).position.y < -10) {
                        running = false;
                        printf("Finished\n");
                }
        }

        return 0;
}
