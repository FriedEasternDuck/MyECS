//
// Created by rooster on 04/10/24.
//

#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include <cstdint>
#include <limits>
#include <vector>

class EntityManager {
public:
        using Entity = std::uint32_t;
        static Entity MAX_ENTITIES;
        static Entity NEXT_ENTITY_ID; // initialised to 1,  0 is invalid
        std::vector<Entity> freeEntities; // add freed entities and take new ID's from back
public:
        [[nodiscard]] Entity createEntity();

        void freeEntity(Entity entity);
};


#endif //ENTITYMANAGER_H
