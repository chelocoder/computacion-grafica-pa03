# PA03 - Parque de la Identidad Huanca

Proyecto desarrollado para el curso de Computación Gráfica de la Universidad Continental.

La escena representa una versión 3D del Parque de la Identidad Huanca de Huancayo. En este Producto Académico 03 se trabajó sobre el renderizado de la escena desarrollada anteriormente, incorporando iluminación, materiales, sombreado, texturas, control de visibilidad y un efecto complementario basado en la animación de una fuente de luz puntual.

## Integrantes

- Juan Marcelo Chamorro Avendaño
- Henry Alan Espejo Villavicencio
- Hector Felipe Urbina Pariona

## Tecnologías utilizadas

- C++
- OpenGL
- FreeGLUT
- Visual Studio Code
- MSVC
- Windows 11

## Características implementadas

La escena incluye:

- Portal principal con textura de piedra.
- Muro de piedra.
- Canal generado mediante curva Bézier.
- Mate burilado.
- Monumento.
- Escalinata.
- Bancas.
- Árboles.
- Faroles.
- Jardines.
- Cámara interactiva.
- Proyección perspectiva y ortográfica.
- Depth Buffer.
- Iluminación puntual y direccional.
- Materiales con diferentes propiedades especulares.
- Sombreado suave.
- Texturizado.
- Animación de una fuente de luz puntual.

## Iluminación

Se utilizan dos fuentes de iluminación:

- `GL_LIGHT0`: fuente de luz puntual.
- `GL_LIGHT1`: fuente de luz direccional.

También se utiliza iluminación ambiental global para evitar que las zonas que no reciben luz directa queden completamente oscuras.

La fuente puntual `GL_LIGHT0` incluye:

- Componente ambiental.
- Componente difusa.
- Componente especular.
- Atenuación constante.
- Atenuación lineal.
- Atenuación cuadrática.

La atenuación permite que la influencia de la fuente disminuya conforme aumenta la distancia respecto de los objetos.

## Materiales y sombreado

Los objetos utilizan diferentes valores de:

- `GL_SPECULAR`
- `GL_SHININESS`

Esto permite representar superficies con distintas respuestas frente a la iluminación.

Por ejemplo, el terreno y la piedra presentan una respuesta principalmente mate, mientras que el mate burilado, el agua, el monumento y los faroles presentan una componente especular mayor.

También se utiliza:

```cpp
glShadeModel(GL_SMOOTH);
glEnable(GL_NORMALIZE);include /link /LIBPATH:freeglut\lib freeglut_static.lib opengl32.lib glu32.lib winmm.lib /OUT:PA03.exe


EJECUCIÓN

.\PA03.exe


CONTROLES

← / → : Girar la cámara
↑ / ↓ : Subir o bajar la cámara

Z : Acercar
X : Alejar

P : Cambiar entre perspectiva y ortográfica

B : Mostrar u ocultar puntos de control Bézier

M : Cambiar el mate entre sólido y wireframe

A / D : Girar el monumento

Q / E : Girar toda la escena

1 : Activar o desactivar la luz puntual

2 : Activar o desactivar la luz direccional

3 : Cambiar la intensidad de la luz principal

T : Activar o desactivar la textura del portal

R : Activar o detener la animación de la luz puntual

ESC : Salir del programa


CARACTERÍSTICAS PRINCIPALES

- Cámara interactiva
- Depth Buffer
- Luz puntual
- Luz direccional
- Iluminación ambiental
- Materiales con componente especular y brillo
- Sombreado suave
- Textura BMP aplicada al portal
- Curva Bézier
- Superficie de revolución
- Modo wireframe
- Animación de la fuente puntual
