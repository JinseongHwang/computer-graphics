//
// Created by jinseonghwang on 22. 3. 24..
//

#include <stdio.h>
#include <vector>
#include "GL/freeglut.h"
#include <math.h>
//#include "CGLab.h"

struct pt {
    double x;
    double y;
};
int width = 500, height = 500;
int arrowIdx = 0;
double PI = 3.14159265;
std::vector <pt> pts;

void DrawCircle(double ctrX, double ctrY, double radius) {

    int res = 100;
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < res; i++) {
        double theta = PI * 2.0 * double(i) / double(res);
        double x = radius * cos(theta) + ctrX;
        double y = radius * sin(theta) + ctrY;
        glVertex2d(x, y);
    }
    glEnd();
}

void DrawObject() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    // Draw Circle
    glLoadIdentity();
    glColor3f(0, 0, 0);
    DrawCircle(0, 0, 0.5);

    // Draw Teapots
    glLoadIdentity();
    glColor3f(1, 0, 0);
    glutWireTeapot(0.2);

    glColor3f(0, 1, 0);
    glTranslatef(0.5, 0, 0);
    glRotated(arrowIdx, 0, 0, 1);
    glutWireTeapot(0.2);

    glColor3f(0, 0, 1);
    glLoadIdentity();
    glRotatef(arrowIdx, 0, 0, 1);
    glTranslatef(0.5, 0, 0);
    glutWireTeapot(0.2);

    glutSwapBuffers();
}

void KeyDown(unsigned char key, int x, int y) {
    switch (key) {
        case 'p':
        case 'P':
            printf("Hello world!\n");
            break;
    }
    glutPostRedisplay();
}

void KeySpecial(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_UP:
            arrowIdx++;
            break;
        case GLUT_KEY_DOWN:
            arrowIdx--;
            break;
    }
    glutPostRedisplay();
}

void Mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        printf("Mouse Click (%d %d)\n", x, y);

    glutPostRedisplay();
}

void Motion(int x, int y) {
    printf("Mouse motion (%d %d)\n", x, y);

    double xd, yd;
    xd = x / 500.0 * 4.0 - 2.0;
    yd = y / 500.0 * 4.0 - 2.0;
    yd *= -1.0;

    glutPostRedisplay();
}

void Init() {
    glViewport(0, 0, width, height);
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-2.0, 2.0, -2.0, 2.0, -1.0, 1.0);
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
    glutKeyboardFunc(KeyDown);
    glutMouseFunc(Mouse);
    glutSpecialFunc(KeySpecial);
    glutMotionFunc(Motion);
    glutIdleFunc(DrawObject);
    glutMainLoop();
}