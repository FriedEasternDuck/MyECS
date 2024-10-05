//
// Created by rooster on 05/10/24.
//

#ifndef SYSTEMBASE_H
#define SYSTEMBASE_H
#include <cstdint>

using Entity = std::uint32_t;

class Scene;


class SystemBase {
public:
        virtual ~SystemBase() = default;
        virtual void update(Scene &scene, Entity entity) = 0;
};

#endif //SYSTEMBASE_H
