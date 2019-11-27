//
// Created by jaimi on 24/11/2019.
//

#include <vector>
#include "sphere.h"
#include "math.h"
#include <iostream>

using namespace std;
Sphere::Sphere(Vector3 color) : Object(color) {
}

//returns all times of intersection of a ray with this sphere object
double Sphere::hit(const Ray &ray) {

    Vector3 genRayOrigin = this->inverseTransformMatrix.transform(ray.origin, 1);
    Vector3 genRayDirection =  this->inverseTransformMatrix.transform(ray.direction, 0);

    double a, b, c;
    a = genRayDirection.length2();
    b = 2 * genRayDirection.dot(genRayOrigin - Vector3(0,0,0));
    c = (genRayOrigin - Vector3(0,0,0)).length2() - 1;
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
    newPoint = inverseTransformMatrix.transform(newPoint,1);
    Vector3 vector = transposedTransformMatrix.transform((-newPoint).normalize(), 0).normalize();
    return vector;

}
