//
// Created by jinseonghwang on 22. 3. 24..
//

#include <stdio.h>
#include <math.h>
#include <vector>
#include "GL/freeglut.h"
#include "GL/freeglut_ext.h"

struct pt {
    double x;
    double y;
    double z;
};
int width = 500, height = 500;
int arrowIdx = 0;
double PI = 3.14159265;
double PI20 = 3.14159265 * 2.0;
std::vector <pt> pts;

void DrawObject() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    glScaled(1.0, 0.5, 1.0);

    // Red Teapot
    glColor3f(1, 0, 0);
    glTranslatef(-0.6, 0.6, 0);
    glRotated(-45, 0, 0, 1);
    glutWireTeapot(0.2);

    // Blue Teapot
    glLoadIdentity();
    glColor3f(0, 0, 1);
    glutWireTeapot(0.2);

    glutSwapBuffers();
    glFlush();
}

void Init() {
    glViewport(0, 0, width, height);
    glClearColor(1.0, 1.0, 1.0, 1.0);
}

int main(int argc, char **argv) {
    int mode = GLUT_RGB | GLUT_DOUBLE;

    glutInit(&argc, argv);
    glutInitDisplayMode(mode);
    glutInitWindowPosition(300, 300);
    glutInitWindowSize(500, 500);
    glutCreateWindow("OpenGL");
    glutSetWindowTitle("DAU CG");

    Init();
    glutDisplayFunc(DrawObject);
    glutMainLoop();
}