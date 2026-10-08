#include <GL/glut.h>
#include <cstdlib>

#include "Camera.h"
#include "Scene.h"
#include "Curves.h"
#include "Lighting.h"
#include "Texture.h"

#include <cstdio>

// ============================================================
// PRODUCTO ACADEMICO 03 - COMPUTACION GRAFICA
// Escena 3D: Parque de la Identidad Huanca - Huancayo
//
// Iluminacion, materiales, sombreado,
// texturizado y visibilidad.
// ============================================================

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    configurarProyeccion();

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    aplicarCamara();
    configurarIluminacion();

    dibujarEscena();
    dibujarIndicadorLuz();

    glutSwapBuffers();
}

void reshape(int width, int height) {
    redimensionarCamara(width, height);
    glutPostRedisplay();
}

void timer(int value) {
    if (animacionLuzActiva) {
        anguloLuz += velocidadLuz;

        if (anguloLuz >= 360.0f)
            anguloLuz -= 360.0f;

        glutPostRedisplay();
    }

    glutTimerFunc(
        16,
        timer,
        0
    );
}

void teclado(unsigned char tecla, int x, int y) {
    switch (tecla) {
        case 'm':
        case 'M':
            modoWireframe = !modoWireframe;
            break;

        case 'b':
        case 'B':
            mostrarPuntosControl = !mostrarPuntosControl;
            break;

        case 'a':
        case 'A':
            anguloMonumento += 5.0f;
            break;

        case 'd':
        case 'D':
            anguloMonumento -= 5.0f;
            break;

        case 'q':
        case 'Q':
            rotacionEscena += 5.0f;
            break;

        case 'e':
        case 'E':
            rotacionEscena -= 5.0f;
            break;

        case 'p':
        case 'P':
            perspectiva = !perspectiva;
            break;

        case '1':
            luzPuntualActiva = !luzPuntualActiva;
            break;

        case '2':
            luzDireccionalActiva = !luzDireccionalActiva;
            break;

        case '3':
            intensidadLuzPrincipal += 0.20f;

            if (intensidadLuzPrincipal > 1.60f)
                intensidadLuzPrincipal = 0.40f;

            break;

        case 't':
        case 'T':
            texturaActiva = !texturaActiva;
            printf("Textura: %s\n", texturaActiva ? "ACTIVADA" : "DESACTIVADA");
            break;

        case 'z':
        case 'Z':
            distanciaCamara -= 1.0f;

            if (distanciaCamara < 10.0f)
                distanciaCamara = 10.0f;

            break;

        case 'x':
        case 'X':
            distanciaCamara += 1.0f;

            if (distanciaCamara > 50.0f)
                distanciaCamara = 50.0f;

            break;
        case 'r':
        case 'R':
            animacionLuzActiva =
                !animacionLuzActiva;

            printf(
                "Animacion de luz: %s\n",
                animacionLuzActiva
                    ? "ACTIVADA"
                    : "PAUSADA"
            );

            break;

        case '4':
            velocidadLuz -= 0.25f;

            if (velocidadLuz < 0.25f)
                velocidadLuz = 0.25f;

            printf(
                "Velocidad luz: %.2f\n",
                velocidadLuz
            );

            break;

        case '5':
            velocidadLuz += 0.25f;

            if (velocidadLuz > 4.0f)
                velocidadLuz = 4.0f;

            printf(
                "Velocidad luz: %.2f\n",
                velocidadLuz
            );

            break;
        
        case '6':
            animacionLuzActiva = false;
            anguloLuz = 0.0f;
            printf("Luz fija: 0 grados\n");
            break;

        case '7':
            animacionLuzActiva = false;
            anguloLuz = 90.0f;
            printf("Luz fija: 90 grados\n");
            break;

        case '8':
            animacionLuzActiva = false;
            anguloLuz = 180.0f;
            printf("Luz fija: 180 grados\n");
            break;

        case '9':
            animacionLuzActiva = false;
            anguloLuz = 270.0f;
            printf("Luz fija: 270 grados\n");
            break;
        
        case 27:
            exit(0);
            break;
    }

    glutPostRedisplay();
}

void teclasEspeciales(int tecla, int x, int y) {
    switch (tecla) {
        case GLUT_KEY_LEFT:
            anguloCamara -= 4.0f;
            break;

        case GLUT_KEY_RIGHT:
            anguloCamara += 4.0f;
            break;

        case GLUT_KEY_UP:
            alturaCamara += 0.5f;

            if (alturaCamara > 25.0f)
                alturaCamara = 25.0f;

            break;

        case GLUT_KEY_DOWN:
            alturaCamara -= 0.5f;

            if (alturaCamara < 2.0f)
                alturaCamara = 2.0f;

            break;
    }

    glutPostRedisplay();
}

void inicializar() {
    glClearColor(0.55f, 0.78f, 0.92f, 1.0f);

    glEnable(GL_DEPTH_TEST);

    inicializarIluminacion();
    inicializarTexturas();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(anchoVentana, altoVentana);
    glutInitWindowPosition(100, 50);

    glutCreateWindow(
        "PA03 - Parque de la Identidad Huanca - Juan Marcelo Chamorro"
    );

    inicializar();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(teclado);
    glutSpecialFunc(teclasEspeciales);

    glutTimerFunc(
        16,
        timer,
        0
    );

    glutMainLoop();

    return 0;
}
