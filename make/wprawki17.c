#include <GL/glut.h>
#include <math.h>

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
#define SZARY 0.75, 0.75, 0.75

//============================================
// Geometria:

typedef struct {
  double  x, y, z;
}  wektor;

wektor  sum_wekt(wektor w1, wektor w2) {
  wektor w;
  w.x = w1.x + w2.x;
  w.y = w1.y + w2.y;
  w.z = w1.z + w2.z;
  return w;
}

wektor  ilrz_wekt(double t, wektor w) {
  wektor w1;
  w1.x = t * w.x;
  w1.y = t * w.y;
  w1.z = t * w.z;
  return w1;
}

double  dlug_wekt(wektor w) {
  return sqrt(w.x*w.x + w.y*w.y + w.z*w.z);
}

//============================================
// Fizyka:

#define g 10
// przyspieszenie grawitacyjne: 10 m/s^2
#define opor 0.01
// wsp. oporu powietrza
#define DT 0.01
// przyrost czasu
#define WLK_SLADU 100000

typedef struct {
  double  prom;  // promien
  wektor  r, v;  // polozenie i predkosc
}  pilka;

pilka  nast_pilka(pilka k, wektor a, double dt) {
  // zmiana kulki poddanej przyspieszeniu  a  przez czas  dt
  pilka k1;
  k1.v = sum_wekt(k.v, ilrz_wekt(dt, a));  // k.v + dt*a
  k1.r = sum_wekt(
           sum_wekt(k.r, ilrz_wekt(dt, k.v)),
	   ilrz_wekt(dt*dt/2, a)
	 );  // k.r + dt*k.v + 0.5*dt^2*a
  k1.prom = k.prom;
  return k1;
}

wektor przysp(pilka p) {
  // przyspieszenie dzialajace na pilke  p
  /* przyspieszenie od oporu powietrza jest proporcjonalne do kwadratu
     predkosci i przeciwnie skierowane: */
  wektor prz = ilrz_wekt(-opor * dlug_wekt(p.v), p.v);
  /* do tego dochodzi grawitacja: */
  wektor graw = {0, -g, 0};
  return  sum_wekt(prz, graw);
}

pilka nowa_pilka(pilka p) {
  if (p.r.y <= p.prom)  p.v.y = -p.v.y;  // odbicie od podlogi
  return  nast_pilka(p, przysp(p), DT);
}

// poczatkowa pilka:
pilka pp = {1, {-13, 23, 0}, {1.8, 0, 0}};

wektor slad[WLK_SLADU];  // poprzednie polozenia pp
int wlk_sladu = 0;;

//============================================
// Geometria obrazka:

void geom(int w, int h) {
  glMatrixMode(GL_PROJECTION); glLoadIdentity();
  glOrtho(-15,15, 0,25, -30,30);
}

//============================================
// Scena:

void wyswietl(void) {
  glClear(GL_COLOR_BUFFER_BIT); glClear(GL_DEPTH_BUFFER_BIT);
  glColor3d(CZERW);
  glPushMatrix(); glTranslated(pp.r.x, pp.r.y, pp.r.z);
    glutSolidSphere(pp.prom, 20, 16);
  glPopMatrix();
  glPointSize(1); glColor3d(CZARN);
  glBegin(GL_POINTS);
    for (int i=0; i<wlk_sladu; i++)
      glVertex3d(slad[i].x, slad[i].y, slad[i].z);
  glEnd();
  glFlush();
}

void  timer(int v) {
  glMatrixMode(GL_MODELVIEW); glLoadIdentity();
  slad[wlk_sladu] = pp.r; wlk_sladu++;
  pp = nowa_pilka(pp);
  glutPostRedisplay();
  glutTimerFunc(5, timer, v);
}

//============================================

int main(int ile_arg, char* arg[]) {
  glutInit(&ile_arg, arg);
  glutInitWindowSize(400, 300);
  glutInitWindowPosition(20, 10);
  glutCreateWindow(arg[0]);
  glEnable(GL_DEPTH_TEST);

  glClearColor(ZOLTY, 0.0);
  glutReshapeFunc(geom);
  glutDisplayFunc(wyswietl);
  glutTimerFunc(5, timer, 0);
  glutMainLoop();
  return 0;
}
