//
// Created by jaimi on 24/11/2019.
//

#include <vector>
#include "sphere.h"
#include "math.h"
#include <iostream>

using namespace std;
Sphere::Sphere(Vector3 color, Vector3 center, double radius) : Object(color) {
    this->center = center;
    this->radius = radius;
}

//returns all times of intersection of a ray with this sphere object
double Sphere::hit(const Ray &ray) {
    double a, b, c;
    a = ray.direction.length2();
    b = 2 * ray.direction.dot(ray.origin - center);
    c = (ray.origin - center).length2() - radius*radius;
    double d = b*b - 4*a*c;
    if (d < 0 ) { //ray misses
        return -1; // no intersectionpoints
    }else{
        d = sqrt(d);
        double t1 = ((-1 * b) + d) / (2 * a);
        double t2 = ((-1 * b) - d) / (2 * a);
        if(t1>0.0001){
            if(t2>0.0001){
                if(t1<t2){
                    return t1;
                }else{
                    return t2;
                }
            }else{
                return t1;
            }
        }else if(t2>0.0001){
            return t2;
        }else{
            return -1;
        }
    }
}

Vector3 Sphere::getNormal(const Vector3 point) const{
    Vector3 newPoint = Vector3(point.x,point.y,point.z);
    Vector3 vector = (( newPoint- center)*(-1/radius)).normalize();
    return vector;

}
