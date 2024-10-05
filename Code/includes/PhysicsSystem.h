//
// Created by rooster on 05/10/24.
//

#ifndef PHYSICSSYSTEM_H
#define PHYSICSSYSTEM_H
#include "Components.h"
#include "SystemBase.h"


constexpr float GRAVITY = 9.81f;

class PhysicsSystem : public SystemBase {
public:

        void update(Scene& scene) override;
};


#endif //PHYSICSSYSTEM_H
