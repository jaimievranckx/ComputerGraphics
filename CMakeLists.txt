cmake_minimum_required(VERSION 3.15)
project(ComputerGraphics)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ComputerGraphics
        camera.cpp
        camera.h
        CMakeLists.txt
        lightSource.cpp
        lightSource.h
        main.cpp
        object.cpp
        object.h
        ray.cpp
        ray.h
        scene.cpp
        scene.h
        matrix.cpp
        matrix.h
        sphere.cpp
        sphere.h
        square.cpp
        square.h
        vector3.cpp
        vector3.h triangle.cpp triangle.h)
target_link_libraries(ComputerGraphics -lopengl32 -lglew32 -lfreeglut -lglu32)
