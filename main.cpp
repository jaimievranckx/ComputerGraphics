#include <iostream>
#include "scene.h"
#include "sphere.h"
#include "square.h"
#include <cmath>
#include <vector>
#include <GL/glew.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glext.h>
#include <cfloat>

using namespace std;

//Global Variables
Scene scene;
int lastTime;
int delta;
int width = 500;
int height = 500;


void ReSizeGLScene(int width, int height)             // Resize And Initialize The GL Window
{
    if (height == 0)                              // Prevent A Divide By Zero By
    {
        height = 1;                           // Making Height Equal One
    }
    glViewport(0, 0, width, height);                    // Reset The Current Viewport
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluOrtho2D( 0.0, 500.0, 500.0,0.0 );                      // Reset The Modelview Matrix
}

Vector3 shade(Ray& ray,Object& object,double t){
    Vector3 hitpoint = ray.origin + ray.direction * t;
    Vector3 normal = object.getNormal(hitpoint);
    Vector3 color = Vector3(0,0,0);
    for(LightSource lightSource : scene.lightSources) {
        Vector3 pos = lightSource.position;
        Vector3 lightDir = hitpoint - pos;
        Vector3 minlightDIR = pos - hitpoint;
        minlightDIR = minlightDIR.normalize();
        Ray testray = Ray(hitpoint,minlightDIR);
        bool shadow = false;
        for (Object* objecttemp : scene.objects) {
            if(objecttemp == &object){

            }else {
                t = (*objecttemp).hit(testray);
                if (t != -1&& t < abs(hitpoint.length())) {
                    shadow = true;
                }
            }
        }
        if(!shadow) {
            lightDir.normalize();
            float mDots = normal.dot(lightDir);
            if (mDots > 0) {
                Vector3 diffuse = object.color * mDots * lightSource.color;
                color = color + diffuse;
            } else {
                color = color + scene.backgroundColor;
            }
        }else{
            color = color + scene.backgroundColor;
        }
    }
    return color.maxValue(255);
}
void renderScene(void)
{
    glPopMatrix();
    glutSwapBuffers();
    glFlush();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glBegin(GL_POINTS);
    Vector3 ray_origin = Vector3(0, 0, -1000);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++)  {
            Vector3 ray_direction = Vector3(i-250, j-250, 1000).normalize();
            double min_t = DBL_MAX;
            Object* nearest_obj = nullptr;
            double t = -1;
            Ray ray = Ray(ray_origin,ray_direction);
            for (Object* object : scene.objects) {
                t=(*object).hit(ray);
                if(t!=-1 ){
                    if(min_t > t){
                        nearest_obj = object;
                        min_t = t;
                    }
                }
            }
            if (nearest_obj == nullptr) {
                // draw backgroundColor of scene
                glColor3ub(scene.backgroundColor.x,scene.backgroundColor.y,scene.backgroundColor.z);
                glVertex2i(i,j);
            }else{
                //draw color of object
                Vector3 color = shade(ray,*nearest_obj, min_t);
                //Vector3 color = nearest_obj->color;
                glColor3ub(color.x,color.y,color.z);
                glVertex2i(i,j);
            }
        }
    }
    glEnd();
    glPopMatrix();
    glutSwapBuffers();
    glFlush();

}
void onIdle()
{
    int time;
    time = glutGet(GLUT_ELAPSED_TIME);
    delta = time - lastTime;
    lastTime = time;
    //Sleep(50);
    glutPostRedisplay();
}

int main(int argc, char **argv) {

    //Initialize Scene
    scene = Scene();

    //Define Camera
    Camera camera = Camera(Vector3(0,0,-5),width,height,180);
    scene.setCamera(&camera);

    //define the object in the scene
    Sphere sphere(Vector3(50, 150, 50), Vector3(250, 0, 0),100);
    scene.addObject(&sphere);
    Sphere sphere2(Vector3(150, 50, 50), Vector3(90, 0, 0),50);
    scene.addObject(&sphere2);
    Sphere sphere3(Vector3(50, 50, 150), Vector3(-250, 100, 0),150);
    scene.addObject(&sphere3);

    Square square(Vector3(255, 0, 0));
    scene.addObject(&square);

    //define the light sources in the scene
    LightSource lightSource(Vector3(0,0,0),Vector3(0.5,0.5,0.5),100);
    scene.addLightSource(lightSource);
    LightSource lightSource2(Vector3(-250,-250,0),Vector3(0.9,0.9,0.9),100);
    scene.addLightSource(lightSource2);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowPosition(80, 80);
    glutInitWindowSize(500,500);

    glutCreateWindow("A Simple OpenGL Program");
    glutDisplayFunc(renderScene);
    glutReshapeFunc(ReSizeGLScene);
    glutIdleFunc(onIdle);
    glClear(GL_COLOR_BUFFER_BIT);
    printf("start");

    glutMainLoop();
    return 0;
}