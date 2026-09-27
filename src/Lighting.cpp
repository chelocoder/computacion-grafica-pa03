#include <GL/glut.h>
#include "Lighting.h"

bool luzPuntualActiva = true;
bool luzDireccionalActiva = true;

float intensidadLuzPrincipal = 1.0f;

void inicializarIluminacion() {
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);

    glEnable(GL_NORMALIZE);
    glShadeModel(GL_SMOOTH);

    GLfloat ambienteGlobal[] = {0.24f, 0.24f, 0.24f, 1.0f};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambienteGlobal);
}

void configurarIluminacion() {
    if (luzPuntualActiva) {
        glEnable(GL_LIGHT0);
    } else {
        glDisable(GL_LIGHT0);
    }

    if (luzDireccionalActiva) {
        glEnable(GL_LIGHT1);
    } else {
        glDisable(GL_LIGHT1);
    }

    GLfloat posicionLuz0[] = {5.0f, 10.0f, 4.0f, 1.0f};

    GLfloat ambienteLuz0[] = {
        0.10f * intensidadLuzPrincipal,
        0.10f * intensidadLuzPrincipal,
        0.08f * intensidadLuzPrincipal,
        1.0f
    };

    GLfloat difusaLuz0[] = {
        0.95f * intensidadLuzPrincipal,
        0.90f * intensidadLuzPrincipal,
        0.80f * intensidadLuzPrincipal,
        1.0f
    };

    GLfloat especularLuz0[] = {
        1.0f * intensidadLuzPrincipal,
        1.0f * intensidadLuzPrincipal,
        1.0f * intensidadLuzPrincipal,
        1.0f
    };

    glLightfv(GL_LIGHT0, GL_POSITION, posicionLuz0);
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambienteLuz0);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, difusaLuz0);
    glLightfv(GL_LIGHT0, GL_SPECULAR, especularLuz0);

    GLfloat direccionLuz1[] = {-1.0f, -1.0f, -0.5f, 0.0f};
    GLfloat ambienteLuz1[] = {0.02f, 0.02f, 0.04f, 1.0f};
    GLfloat difusaLuz1[] = {0.30f, 0.35f, 0.45f, 1.0f};
    GLfloat especularLuz1[] = {0.35f, 0.35f, 0.40f, 1.0f};

    glLightfv(GL_LIGHT1, GL_POSITION, direccionLuz1);
    glLightfv(GL_LIGHT1, GL_AMBIENT, ambienteLuz1);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, difusaLuz1);
    glLightfv(GL_LIGHT1, GL_SPECULAR, especularLuz1);
}

void aplicarMaterial(float especular, float brillo) {
    GLfloat componenteEspecular[] = {especular, especular, especular, 1.0f};

    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, componenteEspecular);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, brillo);
}