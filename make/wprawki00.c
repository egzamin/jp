#include <GL/glut.h>

//============================================
// Definicje kolorow:

#define CZARN 0.0, 0.0, 0.0
#define CZERW 1.0, 0.0, 0.0
#define ZIELO 0.0, 1.0, 0.0
#define ZOLTY 1.0, 1.0, 0.0
#define NIEBI 0.0, 0.0, 1.0
#define MAGEN 1.0, 0.0, 1.0
#define CYJAN 0.0, 1.0, 1.0
#define BIALY 1.0, 1.0, 1.0

//============================================

void geom(int szer_okna, int wys_okna) {
}

//============================================
// Scena:

void wyswietl(void) {
  glClear(GL_COLOR_BUFFER_BIT);
  glFlush();
}

//============================================

int main(int ile_arg, char* arg[]) {
  glutInit(&ile_arg, arg);

  glutInitWindowSize(400, 300);  // 400 x 300 pikseli
  glutInitWindowPosition(20, 10);  // 20 pikseli od lewej i 10 od gory
  glutCreateWindow(arg[0]);  // nazwa okna

  glClearColor(ZOLTY, 0.0);  // kolor tla

  glutReshapeFunc(geom);  // zdefiniowac funkcje  void geom(int s, int w)
  glutDisplayFunc(wyswietl);  // zdefiniowac funkcje  void wyswietl(void)

  glutMainLoop();

  return 0;
}
