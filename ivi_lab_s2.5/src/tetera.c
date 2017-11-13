#include <stdio.h>
#include <GLUT/glut.h>
#include <stdio.h>


static GLint xDegrees = 0;
static GLint yDegrees = 0;
static GLint zDegrees = 0;
static GLint axis = 0;
static GLint stop = 0;
static GLint direction = 1;


void specialKeyboard(int key, int x, int y){
  if(key == GLUT_KEY_RIGHT){
    direction = 1;
  } else if(key == GLUT_KEY_LEFT){
    direction = -1;
  }

}

void change(int * degrees){
  *degrees = ((*degrees)+direction)%360;
}

void rotate(){
  switch(axis){
    case 0: 
      change(&xDegrees);
      break;
    case 1: 
      change(&yDegrees);
      break;
    case 2: 
      change(&zDegrees);
      break;
  }
  glutPostRedisplay();
}

void keyboard (unsigned char key, int x, int y) {

  switch(key){ 
    case 'x':
      axis = 0;
      glutIdleFunc(rotate);
      stop = 0;
      break;
    case 'y':
      axis = 1;
      glutIdleFunc(rotate);
      stop = 0;
      break;
    case 'z':
      axis = 2;
      glutIdleFunc(rotate);
      stop = 0;
      break;
    case 's':
      stop = !stop;
      if(stop)
        glutIdleFunc(NULL);
      else
        glutIdleFunc(rotate);
      break;
  }
}



void render () { 
  /* Limpieza de buffers */
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  /* Carga de la matriz identidad */
  glLoadIdentity();
  /* Posición de la cámara virtual (position, look, up) */
  gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
  
  glRotatef(xDegrees, 1, 0, 0);
  glRotatef(yDegrees, 0, 1, 0);
  glRotatef(zDegrees, 0, 0, 1);

  /* En color blanco */
  glColor3f( 1.0, 1.0, 1.0 );  

  /* Renderiza la tetera */

  glutWireTeapot(1.5);
  /* Intercambio de buffers... Representation ---> Window */

  

  glutSwapBuffers();      
} 

void resize (int w, int h) { 
  /* Definición del viewport */
  glViewport(0, 0, w, h);

  /* Cambio a transform. vista */
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  /* Actualiza el ratio ancho/alto */
  gluPerspective(50., w/(double)h, 1., 10.);

  /* Vuelta a transform. modelo */
  glMatrixMode(GL_MODELVIEW);
}

int main (int argc, char* argv[]) { 
  glutInit( &argc, argv ); 
  glutInitDisplayMode( GLUT_RGB | GLUT_DOUBLE ); 
  glutInitWindowSize(640, 480); 
  glutCreateWindow( "IVI - Sesion 2" ); 
  glEnable (GL_DEPTH_TEST);
  
  /* Registro de funciones de retrollamada */
  glutDisplayFunc(render); 
  glutReshapeFunc(resize); 
  glutKeyboardFunc(keyboard);
  glutSpecialFunc(specialKeyboard);
  
  /* Bucle de renderizado */
  glutMainLoop();  
  
  return 0; 
} 
