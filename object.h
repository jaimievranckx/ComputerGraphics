//
// Created by jaimi on 24/11/2019.
//

#ifndef COMPUTERGRAPHICS_OBJECT_H
#define COMPUTERGRAPHICS_OBJECT_H

#include "vector3.h"
#include "ray.h"

class Object {
public:
    Vector3 color;

    Object(Vector3 color);
    virtual double hit(const Ray& ray) = 0;
    virtual Vector3 getNormal(const Vector3 point) const = 0;


};


#endif //COMPUTERGRAPHICS_OBJECT_H
