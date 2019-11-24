//
// Created by jaimi on 24/11/2019.
//

#include "camera.h"
Camera::Camera() {}
Camera::Camera(Vector3 position, int width, int height,int fov) {
    this->position = position;
    this->width = width;
    this->height = height;
    this->fov = fov;
}
