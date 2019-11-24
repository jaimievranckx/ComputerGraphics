//
// Created by jaimi on 24/11/2019.
//

#ifndef COMPUTERGRAPHICS_CAMERA_H
#define COMPUTERGRAPHICS_CAMERA_H

#include "vector3.h"

class Camera {
public:
    Camera();

    Vector3 position;
    int width;
    int height;
    int fov;
    Camera(Vector3 position,int width,int height,int fov);
};


#endif //COMPUTERGRAPHICS_CAMERA_H
