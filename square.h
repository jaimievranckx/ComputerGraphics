//
// Created by jaimi on 24/11/2019.
//

#ifndef COMPUTERGRAPHICS_SQUARE_H
#define COMPUTERGRAPHICS_SQUARE_H
#include "vector3.h"
#include "ray.h"
#include "object.h"
#include "triangle.h"


class Square : public Object{
public:
    Square(Vector3 color);

    Triangle triangle0;
    Triangle triangle1;
    void scale(Vector3 scale);
    void translate(Vector3 translate);
    double hit(const Ray& ray);
    Vector3 getNormal(const Vector3 point) const;
    void rotateX(double angle);
    void rotateY(double angle);
    void rotateZ(double angle);
};


#endif //COMPUTERGRAPHICS_SQUARE_H
