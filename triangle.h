//
// Created by jaimi on 27/11/2019.
//

#ifndef COMPUTERGRAPHICS_TRIANGLE_H
#define COMPUTERGRAPHICS_TRIANGLE_H

#include "vector3.h"
#include "object.h"

class Triangle : public Object{

public:


    Triangle(Vector3 color, Vector3 p0, Vector3 p1, Vector3 p2);

    Triangle(Vector3 color);

    Triangle();

    Vector3 p0;
    Vector3 p1;
    Vector3 p2;
    double hit(const Ray& ray);
    Vector3 getNormal(const Vector3 point) const;

};


#endif //COMPUTERGRAPHICS_TRIANGLE_H
