//
// Created by jaimi on 24/11/2019.
//

#ifndef COMPUTERGRAPHICS_SQUARE_H
#define COMPUTERGRAPHICS_SQUARE_H
#include "vector3.h"
#include "ray.h"
#include "object.h"


class Square : public Object{
public:

    double hit(const Ray& ray);
    Vector3 getNormal(const Vector3 point) const;
    Square(Vector3 color);
};


#endif //COMPUTERGRAPHICS_SQUARE_H
