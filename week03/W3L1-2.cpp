//
// Created by jinseonghwang on 22. 3. 17..
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

void DrawAxis() {
    glLineWidth(3.0);
    glBegin(GL_LINES);
    glColor3f(1, 0, 0);
    glVertex2f(0, 0);
    glVertex2f(1, 0);
    glColor3f(0, 1, 0);
    glVertex2f(0, 0);
    glVertex2f(0, 1);
    glColor3f(0, 0, 1);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0, 1);
    glEnd();
}

void DrawObject() {
    glClear(GL_COLOR_BUFFER_BIT);

    glLineWidth(3.0);

    // X축
    glColor3f(1, 0, 0);
    glBegin(GL_LINES);
    glVertex2i(-1, 0);
    glVertex2i(1, 0);
    glEnd();

    // Y축
    glColor3f(1, 1, 0);
    glBegin(GL_LINES);
    glVertex2i(0, -1);
    glVertex2i(0, 1);
    glEnd();

    // Z축
    glColor3f(0, 1, 0);
    glPointSize(10.0);
    glBegin(GL_POINTS);
    glVertex2i(0, 0);
    glEnd();

    // Red Teapot
    glColor3f(1, 0, 0);
    glutWireTeapot(0.5);

    // Blue Teapot
    glColor3f(0, 0, 1);
    glTranslatef(1, 0, 0);
    glutWireTeapot(0.5);

    glutSwapBuffers();
    glFlush();
}

void DrawTranslation() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    DrawAxis();

    glLineWidth(1.0);
    glColor3f(1, 0, 0);
    glutWireTeapot(0.2);
    glTranslatef(0.5, 0, 0);
    glColor3f(0, 0, 1);
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
//    glutDisplayFunc(DrawObject);
    glutDisplayFunc(DrawTranslation);
    glutKeyboardFunc(KeyDown);
    glutMouseFunc(Mouse);
    glutSpecialFunc(KeySpecial);
    glutMotionFunc(Motion);
//    glutIdleFunc(DrawObject);
    glutIdleFunc(DrawTranslation);
    glutMainLoop();
}