//
// Created by jaimie vranckx
//

#ifndef COMPUTERGRAPHICS_VECTOR3_H
#define COMPUTERGRAPHICS_VECTOR3_H


class Vector3 {
public:

    double x;
    double y;
    double z;

    /*-----------------   Initializers   -----------------*/

    Vector3(double,double,double);

    Vector3();

    /*-----------------   Operations   -----------------*/

    Vector3 operator * (const double&) const;
    Vector3 operator * (const Vector3&) const;
    Vector3 operator - (const Vector3&) const;
    Vector3 operator - () const;
    Vector3 operator + (const Vector3&) const;
    bool operator == (const Vector3&)const;
    bool operator != (const Vector3&)const;

    Vector3 maxValue(int max);
    double length() const;
    double length2() const;
    double dot(const Vector3&) const;
    Vector3 cross(const Vector3&) const;
    Vector3& normalize();

    /*-----------------   Print   -----------------*/

    void print() const;
};


#endif //COMPUTERGRAPHICS_VECTOR3_H
