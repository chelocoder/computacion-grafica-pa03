#pragma once

extern float anguloCamara;
extern float alturaCamara;
extern float distanciaCamara;

extern bool perspectiva;

extern int anchoVentana;
extern int altoVentana;

void configurarProyeccion();
void aplicarCamara();
void redimensionarCamara(int width, int height);