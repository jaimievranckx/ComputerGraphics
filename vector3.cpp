//
// Created by jaimi on 24/11/2019.
//

#include "vector3.h"
#include <cmath>
#include <iostream>

using namespace std;

/*-----------------   Initializers   -----------------*/

Vector3::Vector3(double x, double y, double z){
    this->x = x;
    this->y = y;
    this->z = z;
}

Vector3::Vector3() {}

/*-----------------   Operations   -----------------*/

//Add vectors
Vector3 Vector3::operator + (const Vector3& v) const {
    return Vector3(x + v.x, y + v.y, z + v.z);
}

//Subtract vectors
Vector3 Vector3::operator - (const Vector3& v) const {
    return Vector3(x - v.x, y - v.y, z - v.z);
}

//Multiply vector with constant
Vector3 Vector3::operator * (const double& xn) const {
    return Vector3(xn*x, xn*y, xn*z);
}

//Multiply vectors
Vector3 Vector3::operator * (const Vector3& v) const {
    return Vector3(v.x*x, v.y*y, v.z*z);
}

//Compare vectors
bool Vector3::operator == (const Vector3& v)const {
    return (((*this)-v).length2()<0.1);
}

//Compare vectors
bool Vector3::operator != (const Vector3& v)const {
    return !(((*this)-v).length2()<0.1);
}

//Returns squared length of vector
double Vector3::length() const {
    return sqrt(length2());
}

//Returns length of vector
double Vector3::length2() const {
    return dot(*this);
}

//Vectors dot product
double Vector3::dot(const Vector3& v) const {
    return v.x*x + v.y * y + v.z * z;
}

//Vectors cross product
Vector3 Vector3::cross(const Vector3& v) const{
    double xn = y*v.z - z*v.y;
    double yn = z*v.x - x*v.z;
    double zn = x*v.y - y*v.x;
    return Vector3(xn, yn, zn);
}

//Normalize vector length on 1
Vector3& Vector3::normalize(){
    double l = length();
    x/=l;
    y/=l;
    z/=l;
    return *this;
}

/*-----------------   Print   -----------------*/

//Print vector
void Vector3::print() const{
    cout<<x<<" "<<y<<" "<<z<<endl;
}

static int max(int val,int max) {
    return (max > 255) ? 255 : val;
}
Vector3 Vector3::maxValue(int maximum) {
    return Vector3(max(x,maximum), max(y,maximum), max(z,maximum));
}

Vector3 Vector3::operator-() const {
    return Vector3(-x,-y,-z);
}






