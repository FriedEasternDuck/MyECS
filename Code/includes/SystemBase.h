//
// Created by rooster on 05/10/24.
//

#ifndef SYSTEMBASE_H
#define SYSTEMBASE_H

class Scene;


class SystemBase {
public:
        virtual ~SystemBase() = default;
        virtual void update(Scene &scene) = 0;
};

#endif //SYSTEMBASE_H
