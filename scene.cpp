//
// Created by jaimie Vranckx
//

#include "scene.h"

Scene::Scene() {}

void Scene::addObject(Object *object) {
    this->objects.push_back(object);
}

void Scene::addLightSource(LightSource light) {
    this->lightSources.push_back(light);
}

void Scene::setCamera(Camera *camera) {
    this->camera = *camera;
}