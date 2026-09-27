#include <GL/glut.h>
#include <cmath>
#include "Camera.h"

const float PI_CAMARA = 3.14159265f;

float anguloCamara = 35.0f;
float alturaCamara = 10.0f;
float distanciaCamara = 26.0f;

bool perspectiva = true;

int anchoVentana = 1000;
int altoVentana = 700;

void configurarProyeccion() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    float aspecto = (float)anchoVentana / (float)altoVentana;

    if (perspectiva) {
        gluPerspective(60.0, aspecto, 0.1, 100.0);
    } else {
        float tam = 15.0f;

        if (aspecto >= 1.0f) {
            glOrtho(-tam * aspecto, tam * aspecto, -tam, tam, -100.0, 100.0);
        } else {
            glOrtho(-tam, tam, -tam / aspecto, tam / aspecto, -100.0, 100.0);
        }
    }

    glMatrixMode(GL_MODELVIEW);
}

void aplicarCamara() {
    float radianes = anguloCamara * PI_CAMARA / 180.0f;
    float camX = sin(radianes) * distanciaCamara;
    float camZ = cos(radianes) * distanciaCamara;

    gluLookAt(
        camX, alturaCamara, camZ,
        0.0f, 1.5f, 0.0f,
        0.0f, 1.0f, 0.0f
    );
}

void redimensionarCamara(int width, int height) {
    if (height == 0)
        height = 1;

    anchoVentana = width;
    altoVentana = height;

    glViewport(0, 0, width, height);
}