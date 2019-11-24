//
// Created by jaimie Vranckx
//

#ifndef COMPUTERGRAPHICS_SCENE_H
#define COMPUTERGRAPHICS_SCENE_H

#include "lightSource.h"
#include <list>
#include "object.h"
#include "camera.h"

using namespace std;

class Scene {
public:
    list<Object*> objects;
    list<LightSource> lightSources;
    Camera camera;
    Vector3 backgroundColor = Vector3(0,0,0);
    Scene();
    void addObject(Object *object);
    void addLightSource(LightSource light);
    void setCamera(Camera *camera);
};


#endif //COMPUTERGRAPHICS_SCENE_H
