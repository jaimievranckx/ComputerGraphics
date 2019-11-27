//
// Created by jaimi on 27/11/2019.
//

#include "triangle.h"


double Triangle::hit(const Ray &ray) {
    Ray genRay = Ray(this->inverseTransformMatrix.transform(ray.origin, 1),this->inverseTransformMatrix.transform(ray.direction, 0));


    double EPSILON = 0.000001;
    Vector3 P, Q, T;
    double det, inv_det, u, v;
    double t;

    // Edges sharing v0
    Vector3 e1 = p1 - p0;
    Vector3 e2 = p2 - p0;
    // Compute determinant
    P = genRay.direction.cross(e2);
    det = e1.dot(P);

    if (det > -EPSILON && det < EPSILON) {
        // The ray lies within the plane of the triangle
        return -1;
    }
    inv_det = 1.f / det;

    // Calculate the distance from v0 to the start point
    T = genRay.origin - p0;

    // Calculate u parameter and test bound
    u = T.dot(P) * inv_det;
    if (u < 0.f || u > 1.f) {
        // The intersection lies outside of the triangle
        return -1;
    }

    // V parameter
    Q = T.cross(e1);
    v =genRay.direction.dot(Q) * inv_det;

    if (v < 0.f || u + v  > 1.f) {
        // The intersection lies outside of the triangle
        return -1;
    }

    t = e2.dot(Q) * inv_det;

    if (t > EPSILON) {
        // Ray intersection

        return t;
    }

    // No intersection
    return -1;
}

Vector3 Triangle::getNormal(const Vector3 point) const {
    Vector3 e1 = p1 - p0;
    Vector3 e2 = p2 - p0;
    Vector3 normal = e2.cross(e1).normalize();
    return  transposedTransformMatrix.transform(normal, 0).normalize();;
}

Triangle::Triangle(Vector3 color, Vector3 p0,Vector3 p1,Vector3 p2) : Object(color) {
    this->p0 = p0;
    this->p1 = p1;
    this->p2 = p2;
}

Triangle::Triangle(Vector3 color) : Object(color) {}

Triangle::Triangle() {}


