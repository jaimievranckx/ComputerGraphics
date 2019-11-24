//
// Created by jaimi on 22/11/2019.
//

#ifndef COMPUTERGRAPHICS_LIGHTSOURCE_H
#define COMPUTERGRAPHICS_LIGHTSOURCE_H
#include "vector3.h"

class LightSource {
public:
    Vector3 position;
    Vector3 color;
    int intensity;
    LightSource(Vector3 position, Vector3 color,int intensity);
};

#endif //COMPUTERGRAPHICS_LIGHTSOURCE_H
