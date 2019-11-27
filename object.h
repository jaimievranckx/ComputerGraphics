//
// Created by jaimi on 24/11/2019.
//

#ifndef COMPUTERGRAPHICS_OBJECT_H
#define COMPUTERGRAPHICS_OBJECT_H

#include "vector3.h"
#include "ray.h"
#include "matrix.h"

class Object {
public:
    Vector3 color;
    Matrix transformMatrix;
    Matrix inverseTransformMatrix;
    Matrix transposedTransformMatrix;

    Object(Vector3 color);

    Object();

    virtual double hit(const Ray& ray) = 0;
    virtual Vector3 getNormal(const Vector3 point) const = 0;

    virtual void scale(Vector3 scale);

    virtual void translate(Vector3 translate);

    virtual void rotateX(double angle);

    virtual void rotateY(double angle);

    virtual void rotateZ(double angle);
};


#endif //COMPUTERGRAPHICS_OBJECT_H
