#include <windows.h>
#ifdef __APPLE__

#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

static int slices = 20;
static int stacks = 20;


static void resize(int width, int height)
{
    const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}
int c = 0;
int d = 0;
static void display(void)
{
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    const double a = t*90.0;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//el kora el 7amra
    glColor3d(1,0,0);
       glPushMatrix();
        glTranslated(0,0,-9);
        glRotated(60,1,0,0);

glutSolidSphere(3,slices,stacks);
    glPopMatrix();
//el kora el beda

     glColor3d(1,1,1);
    glPushMatrix();
        glTranslated(0,-0.8,-7.9);
        glRotated(60,0,0,1);
        glutSolidSphere(2.1,slices,stacks);
    glPopMatrix();
//el bo2 el asfar
        glColor3d(1,1,0);
        glPushMatrix();
        glTranslated(-0.19, -0.4, -5);
       glRotated(-60,0,0,1);
        glutSolidTetrahedron();
    glPopMatrix();

//el 3uon el beda
    glColor3d(1,1,1);
       glPushMatrix();
        glTranslated(-0.4,0.5,-6);
        glRotated(60,1,0,0);

glutSolidSphere(0.6,slices,stacks);
    glPopMatrix();

glutSolidSphere(0.4,slices,stacks);
    glPopMatrix();
    glColor3d(1,1,1);
       glPushMatrix();
        glTranslated(0.4,0.4,-6);
        glRotated(60,1,0,0);

glutSolidSphere(0.6,slices,stacks);
    glPopMatrix();

//Eyes el soda
    glColor3d(0,0,0);
    glPushMatrix();
        glTranslated(0.24,0.34,-5.2);
        glRotated(60,1,0,0);
        glutSolidSphere(0.1,slices,stacks);
    glPopMatrix();

    glColor3d(0,0,0);
    glPushMatrix();
        glTranslated(-0.4,0.4,-5.2);
        glRotated(60,1,0,0);
        glutSolidSphere(0.1,slices,stacks);
    glPopMatrix();
    //el remosh
glColor3d(0,0,0);
    glPushMatrix();
        glTranslated(0,1.3,-6.2);
         glRotated(-60,0,1,0);
        glutSolidCone(0.12,1,slices,stacks);
    glPopMatrix();

    glPushMatrix();
        glTranslated(0.2,1.29,-6.2);
        glRotated(60,0,1,0);
        glutSolidCone(0.12,1,slices,stacks);
    glPopMatrix();
    //el resh

glPushMatrix();
        glTranslated(3.7,-0.7,-8);
        glRotated(-60,0,1,0);
        glutSolidCone(0.2,2,slices,stacks);
    glPopMatrix();

    glPushMatrix();
        glTranslated(3.2,-1.9,-8);
        glRotated(-60,1,1,0);
        glutSolidCone(0.2,2,slices,stacks);
    glPopMatrix();
      glPushMatrix();
        glTranslated(3.9,-1.5,-9.4);
        glRotated(-60,0,1,1);
        glutSolidCone(0.2,4,slices,stacks);
    glPopMatrix();
    //el sha3r
glColor3d(0,0,0);
    glPushMatrix();
        glTranslated(1.4,2.8,-8);
        glRotated(-60,1,1,0);
        glutSolidCube(1.1);
    glPopMatrix();
      glPushMatrix();
        glTranslated(1.4,2.8,-8);
        glRotated(60,1,1,0);
        glutSolidCube(1);
    glPopMatrix();

 //f
    glColor3d(1,0.637,0.865);
    glPushMatrix();
        glTranslated(0.8,2.2,-6.5);
        glRotated(60,1,0,0);
        glutSolidSphere(0.43,slices,stacks);
    glPopMatrix();

    glColor3d(1,0.637,0.865);
    glPushMatrix();
        glTranslated(1.5,1.9,-6.5);
        glRotated(60,1,0,0);
        glutSolidSphere(0.43,slices,stacks);
    glPopMatrix();
    glColor3d(1,0,0.865);
    glPushMatrix();
        glTranslated(1,1.9,-6.3);
        glRotated(60,1,0,0);
       // glRotated(a,0,0,1);
        glutSolidSphere(0.2,slices,stacks);
    glPopMatrix();
    glutSwapBuffers();
}
void KeySet() { DWORD old = 0;
SystemParametersInfo(SPI_GETKEYBOARDDELAY, 0, &old, 0);
SystemParametersInfo(SPI_SETKEYBOARDDELAY,0, &old, 0);
}
static void key(unsigned char key, int x, int y)
{
    KeySet();
    if(key == 27) exit (0);
	else if( (key == 119) && (95 > d) ){
	glTranslatef(0, 1, 0);
	d = d + 1;
	}
	else if( (key == 115) && (d > -95) ){
	glTranslatef(0, -1, 0);
	d = d - 1;
	}
	else if( (key == 97) && (c > -95) ){
	glTranslatef(-1, 0, 0);
	c = c - 1;
	}
	else if( (key == 100) && (95 > c) ){
	glTranslatef(1, 0, 0);
	c = c + 1;
	}
}

static void idle(void)
{
    glutPostRedisplay();
}

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

/* Program entry point */

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("Car");

    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutIdleFunc(idle);
    glutFullScreen();

    glClearColor(0.5,0.5,0.5,0.5);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    glutMainLoop();

    return EXIT_SUCCESS;
}
