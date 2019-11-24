cmake_minimum_required(VERSION 3.15)
project(ComputerGraphics)

set(CMAKE_CXX_STANDARD 14)

add_executable(ComputerGraphics main.cpp scene.cpp scene.h lightSource.h object.cpp object.h sphere.cpp sphere.h vector3.cpp vector3.h ray.cpp ray.h lightSource.cpp camera.cpp camera.h square.cpp square.h)
target_link_libraries(ComputerGraphics -lopengl32 -lglew32 -lfreeglut -lglu32)