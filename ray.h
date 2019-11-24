//
// Created by jaimi on 24/11/2019.
//

#ifndef COMPUTERGRAPHICS_RAY_H
#define COMPUTERGRAPHICS_RAY_H

#include "vector3.h"

class Ray {
public:

    Vector3 origin;
    Vector3 direction;

    Ray(Vector3 origin, Vector3 direction);

    Vector3 getPoint(double t) const;
};


#endif //COMPUTERGRAPHICS_RAY_H
