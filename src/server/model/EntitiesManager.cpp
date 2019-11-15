//
// Created by leobellaera on 6/11/19.
//

#include "EntitiesManager.h"

#define MAX_PROJECTILES_NUMBER 3
#define MAX_ENTITIES_NUMBER 5

EntitiesManager::EntitiesManager(World& stageWorld) :
    entitiesCounter(0),
    world(stageWorld) {}

void EntitiesManager::addProjectile(EntityIdentifier entityIdentifier, float x_pos, float y_pos, b2Vec2 impulse) {
    if (projectiles.size() >= MAX_PROJECTILES_NUMBER|| entities.size() >= MAX_ENTITIES_NUMBER) {
        return;
    }

    Projectile* projectile = world.addProjectile(entityIdentifier, x_pos, y_pos);
    projectile->applyLinearImpulse(impulse);

    projectiles.emplace(entitiesCounter, projectile);
    entities.emplace(entitiesCounter, projectile);
    entitiesCounter++;
}

void EntitiesManager::addEntity(EntityIdentifier entityIdentifier, float x_pos, float y_pos) {
    //todo
    entitiesCounter++;
}

void EntitiesManager::deleteDeadEntities() {
    auto it = entities.begin();
    while (it != entities.end()) {
        if (it->second->isDead()) {
            delete it->second;
            it = entities.erase(it);
        } else {
            it++;
        }
    }
}

void EntitiesManager::updateProjectilesStatus() {
    auto it = projectiles.begin();

    while (it != projectiles.end()) {

        if (it->second->isStill()) {

            EntityIdentifier identifier = it->second->getIdentifier();
            b2Vec2 pos = it->second->getPosition();
            int projectileId = it->first;
            delete it->second;
            it = projectiles.erase(it);

            if (identifier == HEALTHBOOSTER) {

                HealthBooster* healthBooster = world.addHealthBooster(pos.x, pos.y);
                entities.find(projectileId)->second = healthBooster;

            } else if (identifier == STONE) {

                Stone* stone = world.addStone(pos.x, pos.y);
                entities.find(projectileId)->second = stone;

            } else if (identifier == OIL) {

                Oil* oil = world.addOil(pos.x, pos.y);
                entities.find(projectileId)->second = oil;

            } else if (identifier == SPEEDBOOSTER) {

                HealthBooster* healthBooster = world.addHealthBooster(pos.x, pos.y);
                entities.find(projectileId)->second = healthBooster;

            } else if (identifier == MUG) {

                //todo

            }

        } else {
            it++;
        }
    }
}

void EntitiesManager::updateProjectilesFriction() {
    auto it = projectiles.begin();
    while (it != projectiles.end()) {
        it->second->updateFriction();
        it++;
    }
}

std::unordered_map<int, Entity*>& EntitiesManager::getEntities() {
    return entities;
}

EntitiesManager::~EntitiesManager() {
    for (auto & entity : entities) {
        projectiles.erase(entity.first);
        delete (entity.second);
    }

    for (auto & projectile : projectiles) {
        delete (projectile.second);
    }
}