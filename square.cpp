//
// Created by jaimi on 24/11/2019.
//

#include "square.h"
#include "math.h"
double Square::hit(const Ray &ray) {
    double t0 = triangle0.hit(ray);
    double t1 = triangle1.hit(ray);

    if(t0!=-1){
        return t0;
    }else{
        return t1;
    }
}


Vector3 Square::getNormal(const Vector3 point) const {

    return triangle0.getNormal(point);
}

Square::Square(Vector3 color) : Object(color) {
    this->triangle0 = Triangle(color,Vector3(1,-1,0),Vector3(-1,1,0),Vector3(1,1,0));
    this->triangle1 = Triangle(color,Vector3(1,-1,0),Vector3(-1,1,0),Vector3(-1,-1,0));

}

void Square::translate(Vector3 translate) {
    Object::translate(translate);
    triangle0.translate(translate);
    triangle1.translate(translate);

}

void Square::scale(Vector3 scale) {
    Object::scale(scale);
    triangle0.scale(scale);
    triangle1.scale(scale);
}

void Square::rotateX(double angle) {
    Object::rotateX(angle);
    triangle0.rotateX(angle);
    triangle1.rotateX(angle);
}

void Square::rotateY(double angle) {
    Object::rotateY(angle);
    triangle0.rotateY(angle);
    triangle1.rotateY(angle);
}

void Square::rotateZ(double angle) {
    Object::rotateZ(angle);
    triangle0.rotateZ(angle);
    triangle1.rotateZ(angle);
}
