//
// Created by jaimi on 24/11/2019.
//

#ifndef COMPUTERGRAPHICS_SPHERE_H
#define COMPUTERGRAPHICS_SPHERE_H


#include "vector3.h"
#include "ray.h"
#include "object.h"

class Sphere : public Object {

    double hit(const Ray& ray);
    Vector3 getNormal(const Vector3 point) const;

public:
    Sphere(Vector3 color);
};


#endif //COMPUTERGRAPHICS_SPHERE_H
