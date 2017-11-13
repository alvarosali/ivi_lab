Cambios realizados para la compatibilidad con MacOS:

Para que las aplicaciones de OpenGL funcionen correctamente en el sistema operativo de MacOS se he realizado los siguientes cambios.

En helloOpenGL.c: 

	#include <GL/glut.h> 

sustituido por:

	#include <GLUT/glut.h>

En Makefile:

	LDFLAGS := -lglut -lGLU -lGL
sustituido por:

	LDFLAGS := -framework GLUT -framework OpenGL -framework Cocoa