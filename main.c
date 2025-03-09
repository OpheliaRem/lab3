#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include <GL/glut.h>
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <unistd.h>
#include <math.h>
#include "my_obj_parser.h"

float angle = 0.0;
float lx = 0.0f, lz = -1.0f;
float x = 0.0f, z = 5.0f;

void init() {
    glEnable(GL_DEPTH_TEST | GL_TEXTURE_2D);
    glDisable(GL_LIGHTING); 
    glShadeModel(GL_SMOOTH);
    glClearColor(0.5f, 0.5f, 0.5f, 0.0f); // Серый фон

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, 1080.0 / 600.0, 0.1f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
}

void processSpecialKeys(int key, int xx, int yy) {
    float fraction = 0.1f;
    switch (key) {
        case GLUT_KEY_LEFT:
            angle -= 0.01f;
            lx = sin(angle);
            lz = -cos(angle);
            break;
        case GLUT_KEY_RIGHT:
            angle += 0.01f;
            lx = sin(angle);
            lz = -cos(angle);
            break;
        case GLUT_KEY_UP:
            x += lx * fraction;
            z += lz * fraction;
            break;
        case GLUT_KEY_DOWN:
            x -= lx * fraction;
            z -= lz * fraction;
            break;
    }
    glutPostRedisplay(); // Request a redraw
}

void display_function(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // Set up the camera
    gluLookAt(x, 1.0f, z, 
              x + lx, 1.0f, z + lz, 
              0.0f, 1.0f, 0.0f);

    glScalef(0.1f, 0.1f, 0.1f);

    //glColor3f(0.0f, 0.0f, 1.0f);
    glPointSize(2.0);

    glRotatef(angle, 0.0f, 1.0f, 0.0f);

    draw_3d_scene_from_file("/home/artem/programming/c/lab3/resources/cottage.obj");

    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(1080, 600);
    glutCreateWindow("test window");
    init();
    glutDisplayFunc(display_function);
    glutSpecialFunc(processSpecialKeys);
    glutMainLoop();
    return 0;
}