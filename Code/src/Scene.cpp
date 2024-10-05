//
// Created by rooster on 04/10/24.
//

#include "../includes/Scene.h"
#include "../includes/Components.h"
#include "../includes/SystemBase.h"


Scene::Scene()  {

}

Entity Scene::createEntity() {
        const auto entity = entityManager.createEntity();
        _entities.push_back(entity);
        return entity;
}

void Scene::freeEntity(const Entity entity) {
        _positionPool.removeComponent(entity);
        std::erase(_entities, entity);
        entityManager.freeEntity(entity);


}
