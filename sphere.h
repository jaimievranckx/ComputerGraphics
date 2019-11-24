//
// Created by jaimi on 24/11/2019.
//

#ifndef COMPUTERGRAPHICS_SPHERE_H
#define COMPUTERGRAPHICS_SPHERE_H


#include "vector3.h"
#include "ray.h"
#include "object.h"

class Sphere : public Object {
    Vector3 center;
    double radius;

    double hit(const Ray& ray);
    Vector3 getNormal(const Vector3 point) const;

public:
    Sphere(Vector3 color, Vector3 center, double radius);
};


#endif //COMPUTERGRAPHICS_SPHERE_H
