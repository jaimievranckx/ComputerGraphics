//
// Created by jaimi on 24/11/2019.
//

#include "object.h"
#include "matrix.h"

Object::Object(Vector3 color) {
    this->color = color;
    this->transformMatrix = Matrix();
    this->inverseTransformMatrix = this->transformMatrix.inverse();
    this->transposedTransformMatrix = this->inverseTransformMatrix.inverse();

}

void Object::scale(Vector3 scale) {
    transformMatrix = transformMatrix * Matrix(SCALE,Vector3(scale));
    this->inverseTransformMatrix = this->transformMatrix.inverse();
    this->transposedTransformMatrix = this->inverseTransformMatrix.inverse();

}

void Object::translate(Vector3 translate) {
    transformMatrix = transformMatrix * Matrix(TRANSLATE,Vector3(translate));
    this->inverseTransformMatrix = this->transformMatrix.inverse();
    this->transposedTransformMatrix = this->inverseTransformMatrix.inverse();

}

void Object::rotateX(double angle) {
    transformMatrix = transformMatrix * Matrix(ROTATEX,angle);
    this->inverseTransformMatrix = this->transformMatrix.inverse();
    this->transposedTransformMatrix = this->inverseTransformMatrix.inverse();

}

void Object::rotateY(double angle) {
    transformMatrix = transformMatrix * Matrix(ROTATEY,angle);
    this->inverseTransformMatrix = this->transformMatrix.inverse();
    this->transposedTransformMatrix = this->inverseTransformMatrix.inverse();

}

void Object::rotateZ(double angle) {
    transformMatrix = transformMatrix * Matrix(ROTATEZ,angle);
    this->inverseTransformMatrix = this->transformMatrix.inverse();
    this->transposedTransformMatrix = this->inverseTransformMatrix.inverse();

}

Object::Object() {}
