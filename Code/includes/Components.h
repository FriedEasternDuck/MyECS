//
// Created by rooster on 04/10/24.
//

#ifndef COMPONENTS_H
#define COMPONENTS_H

#include <glm/glm.hpp>
#include <cstdint>

using ComponentTypeID = std::uint8_t;

class PositionComponent {
public:
        glm::vec3 position{0.0f, 0.0f, 0.0f};

        bool operator==(const PositionComponent &other) const {
                return position == other.position;
        }
        bool operator!=(const PositionComponent &other) const {
                return position != other.position;
        }
};

class VelocityComponent {
public:
        glm::vec3 velocity{0.0f, 0.0f, 0.0f};
};

class PhysicsComponent {
public:
        explicit PhysicsComponent(const bool gravity) : isEffectedByGravity(gravity) {
        };
        bool isEffectedByGravity;
};

#endif //COMPONENTS_H
