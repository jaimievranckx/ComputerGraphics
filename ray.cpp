//
// Created by jaimi on 24/11/2019.
//

#include "ray.h"

Ray::Ray(Vector3 origin, Vector3 direction){
    this->origin = origin;
    this->direction = direction;
}

Vector3 Ray::getPoint(double t) const{
    return origin + direction * t;
}