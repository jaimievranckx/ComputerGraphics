//
// Created by jaimi on 24/11/2019.
//

#include "square.h"
#include "math.h"
double Square::hit(const Ray &ray) {
    int numHits = 0;
    double denom = ray.direction.z;
    if(fabs(denom)<0.0001) return -1;
    double time = -ray.origin.z;
    if(time <=0.0) return -1;
    double hx = ray.origin.x + ray.direction.x * time;
    double hy = ray.origin.y + ray.direction.y * time;
    if((hx > 1)||(hx < -1)) return -1;
    if((hy > 1)||(hy < -1)) return -1;
    return time;
}

Vector3 Square::getNormal(const Vector3 point) const {
    return Vector3(0,-1,0);
}

Square::Square(Vector3 color) : Object(color) {

}
