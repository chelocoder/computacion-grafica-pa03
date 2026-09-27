#pragma once

extern bool luzPuntualActiva;
extern bool luzDireccionalActiva;
extern float intensidadLuzPrincipal;

void inicializarIluminacion();
void configurarIluminacion();
void aplicarMaterial(float especular, float brillo);