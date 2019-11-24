//
// Created by jaimie vranckx
//
#include "lightSource.h"

LightSource::LightSource(Vector3 position, Vector3 color,int intensity) {
    this->color = color;
    this->position = position;
    this->intensity = intensity;
}