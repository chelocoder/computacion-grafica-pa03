PRODUCTO ACADÉMICO 03 - COMPUTACIÓN GRÁFICA

Proyecto:
Parque de la Identidad Huanca - Huancayo

Docente:
Percy Maldonado Quispe


DESCRIPCIÓN

El proyecto corresponde al Producto Académico 03 del curso de Computación Gráfica.

Se continuó la escena 3D desarrollada en el PA02 y se incorporaron conceptos de renderizado como iluminación, materiales, sombreado, texturas, visibilidad y control de cámara.

La escena incluye portal principal, muro de piedra, canal Bézier, mate burilado, monumento, escalinata, bancas, árboles, faroles y jardines.


TECNOLOGÍAS

- C++
- OpenGL
- FreeGLUT
- Visual Studio Code
- MSVC


ESTRUCTURA DEL PROYECTO

include/
    Camera.h
    Curves.h
    Lighting.h
    Scene.h
    Texture.h

src/
    PA03.cpp
    camera.cpp
    curves.cpp
    Lighting.cpp
    Scene.cpp
    Texture.cpp

textures/
    piedra.bmp


COMPILACIÓN

cl /EHsc /MD /O2 src\PA03.cpp src\Scene.cpp src\camera.cpp src\curves.cpp src\Lighting.cpp src\Texture.cpp /D FREEGLUT_STATIC /D NDEBUG /I freeglut\include /I include /link /LIBPATH:freeglut\lib freeglut_static.lib opengl32.lib glu32.lib winmm.lib /OUT:PA03.exe


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
