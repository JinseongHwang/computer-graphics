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

void DrawObject() {
    glClear(GL_COLOR_BUFFER_BIT);

    glLineWidth(3.0);

    glColor3f(0, 1, 0);
    double radius = 1.0;
    glBegin(GL_POLYGON);
    /**
     * Key-Up 하면 arrowIdx가 증가하면서, N각형이 그려질 때 N이 증가한다.
     * Key-Down 하면 반대로 N각형의 N이 감소한다.
     */
    for (int i = 0; i <= arrowIdx; ++i) {
        double theta = PI * 2.0 * double(i) / double(arrowIdx);
        double x = radius * cos(theta);
        double y = radius * sin(theta);
        glVertex2d(x, y);
    }
    glEnd();
    glFlush();
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
    int mode = GLUT_RGB | GLUT_SINGLE;

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