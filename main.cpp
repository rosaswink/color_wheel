#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <math.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <iostream>
#include <cstdio>
#include <cstdlib>
#define PI 3.141592653589
#define ADJUSTMENT 0.001145915590

using namespace std;

/*----- GLOBAL VARIABLES ------------*/
int button, state = 1;
float r,g,b;
float red, green, blue;

/*----- FUNCTION DECLARATION --------*/
void initScreen();
void display();
void mouseClicks(int but,int sta,int x,int y);

//===== main function ==================================
int main(int argc, char**argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    
    // Create a window
    glutCreateWindow("Application Title");
    glutPositionWindow(0, 0);
    glutReshapeWindow(512, 512);
    
    // Program start here...
    initScreen();
    glutDisplayFunc(display);
    glutMouseFunc(mouseClicks);
    glutMainLoop();
    return 0;
}

//===== initScreen: set up the 2D canvas ==================
void initScreen(){
    glClearColor(0., 0., 0., 0.);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,1.0,0.0,1.0);    // set coord for viewport
    glViewport(0,0,512,512);    // set viewport
}

//===== display: perform OpenGL drawing on the canvas =========
void display(){

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glShadeModel(GL_SMOOTH);
    glBegin(GL_LINES);

    for (float theta=0; theta<(PI/18); theta+=0.001) { //2nd half of red zone
            red = 1;
            green = 0;
            blue = 0;
            glColor3f(0, 0, 0);
            glVertex3f(0.5+0.15*cos(theta),0.5+0.15*sin(theta),0.0);
            glColor3f(red, green, blue);
            glVertex3f(0.5+0.35*cos(theta),0.5+0.35*sin(theta),0.0);
            glColor3f(red, green, blue);
            glVertex3f(0.5+0.35*cos(theta),0.5+0.35*sin(theta),0.0);
            glColor3f(1, 1, 1);
            glVertex3f(0.5+0.5*cos(theta),0.5+0.5*sin(theta),0.0);
        }
    
    green = 0;
    for (float theta=PI/18; theta<PI/3; theta+=0.001) { //1st half of yellow zone
        red = 1;
        blue = 0;
        glColor3f(0, 0, 0);
        glVertex3f(0.5+0.15*cos(theta),0.5+0.15*sin(theta),0.0);
        glColor3f(red, green, blue);
        glVertex3f(0.5+0.35*cos(theta),0.5+0.35*sin(theta),0.0);
        glColor3f(red, green, blue);
        glVertex3f(0.5+0.35*cos(theta),0.5+0.35*sin(theta),0.0);
        glColor3f(1, 1, 1);
        glVertex3f(0.5+0.5*cos(theta),0.5+0.5*sin(theta),0.0);
        green += ADJUSTMENT;
    }
    
    red = 1;
    for (float theta=PI/3; theta<11*PI/18; theta+=0.001) { //2nd half of yellow zone
        green = 1;
        blue = 0;
        glColor3f(0, 0, 0);
        glVertex3f(0.5+0.15*cos(theta),0.5+0.15*sin(theta),0.0);
        glColor3f(red, green, blue);
        glVertex3f(0.5+0.35*cos(theta),0.5+0.35*sin(theta),0.0);
        glColor3f(red, green, blue);
        glVertex3f(0.5+0.35*cos(theta),0.5+0.35*sin(theta),0.0);
        glColor3f(1, 1, 1);
        glVertex3f(0.5+0.5*cos(theta),0.5+0.5*sin(theta),0.0);
        red -= ADJUSTMENT;
    }
    
    for (float theta=11*PI/18; theta<13*PI/18; theta+=0.001) { //green zone
        red = 0;
        green = 1;
        blue = 0;
        glColor3f(0, 0, 0);
        glVertex3f(0.5+0.15*cos(theta),0.5+0.15*sin(theta),0.0);
        glColor3f(red, green, blue);
        glVertex3f(0.5+0.35*cos(theta),0.5+0.35*sin(theta),0.0);
        glColor3f(red, green, blue);
        glVertex3f(0.5+0.35*cos(theta),0.5+0.35*sin(theta),0.0);
        glColor3f(1, 1, 1);
        glVertex3f(0.5+0.5*cos(theta),0.5+0.5*sin(theta),0.0);
    }
    
    blue = 0;
    for (float theta=13*PI/18; theta<PI; theta+=0.001) { //1st half of cyan zone
        red = 0;
        green = 1;
        glColor3f(0, 0, 0);
        glVertex3f(0.5+0.15*cos(theta),0.5+0.15*sin(theta),0.0);
        glColor3f(red, green, blue);
        glVertex3f(0.5+0.35*cos(theta),0.5+0.35*sin(theta),0.0);
        glColor3f(red, green, blue);
        glVertex3f(0.5+0.35*cos(theta),0.5+0.35*sin(theta),0.0);
        glColor3f(1, 1, 1);
        glVertex3f(0.5+0.5*cos(theta),0.5+0.5*sin(theta),0.0);
        blue += ADJUSTMENT;
    }

    green = 1;
    for (float theta=PI; theta<23*PI/18; theta+=0.001) { //2st half of cyan zone
        red = 0;
        blue = 1;
        glColor3f(0, 0, 0);
        glVertex3f(0.5+0.15*cos(theta),0.5+0.15*sin(theta),0.0);
        glColor3f(red, green, blue);
        glVertex3f(0.5+0.35*cos(theta),0.5+0.35*sin(theta),0.0);
        glColor3f(red, green, blue);
        glVertex3f(0.5+0.35*cos(theta),0.5+0.35*sin(theta),0.0);
        glColor3f(1, 1, 1);
        glVertex3f(0.5+0.5*cos(theta),0.5+0.5*sin(theta),0.0);
        green -= ADJUSTMENT;
    }
    
    for (float theta=23*PI/18; theta<(25*PI/18); theta+=0.001) { //blue zone
        red = 0;
        green = 0;
        blue = 1;
        glColor3f(0, 0, 0);
        glVertex3f(0.5+0.15*cos(theta),0.5+0.15*sin(theta),0.0);
        glColor3f(red, green, blue);
        glVertex3f(0.5+0.35*cos(theta),0.5+0.35*sin(theta),0.0);
        glColor3f(red, green, blue);
        glVertex3f(0.5+0.35*cos(theta),0.5+0.35*sin(theta),0.0);
        glColor3f(1, 1, 1);
        glVertex3f(0.5+0.5*cos(theta),0.5+0.5*sin(theta),0.0);
    }
    
    red = 0;
    for (float theta=(25*PI/18); theta<5*PI/3; theta+=0.001) { //1st half of magenta zone
        blue = 1;
        green = 0;
        glColor3f(0, 0, 0);
        glVertex3f(0.5+0.15*cos(theta),0.5+0.15*sin(theta),0.0);
        glColor3f(red, green, blue);
        glVertex3f(0.5+0.35*cos(theta),0.5+0.35*sin(theta),0.0);
        glColor3f(red, green, blue);
        glVertex3f(0.5+0.35*cos(theta),0.5+0.35*sin(theta),0.0);
        glColor3f(1, 1, 1);
        glVertex3f(0.5+0.5*cos(theta),0.5+0.5*sin(theta),0.0);
        red += ADJUSTMENT;
    }
    
    blue = 1;
    for (float theta=5*PI/3; theta<(35*PI/18); theta+=0.001) { //2st half of magenta zone
        red = 1;
        green = 0;
        glColor3f(0, 0, 0);
        glVertex3f(0.5+0.15*cos(theta),0.5+0.15*sin(theta),0.0);
        glColor3f(red, green, blue);
        glVertex3f(0.5+0.35*cos(theta),0.5+0.35*sin(theta),0.0);
        glColor3f(red, green, blue);
        glVertex3f(0.5+0.35*cos(theta),0.5+0.35*sin(theta),0.0);
        glColor3f(1, 1, 1);
        glVertex3f(0.5+0.5*cos(theta),0.5+0.5*sin(theta),0.0);
        blue -= ADJUSTMENT;
    }
    
    for (float theta=35*PI/18; theta<2*PI; theta+=0.001) { //1st half of red zone
        red = 1;
        green = 0;
        blue = 0;
        glColor3f(0, 0, 0);
        glVertex3f(0.5+0.15*cos(theta),0.5+0.15*sin(theta),0.0);
        glColor3f(red, green, blue);
        glVertex3f(0.5+0.35*cos(theta),0.5+0.35*sin(theta),0.0);
        glColor3f(red, green, blue);
        glVertex3f(0.5+0.35*cos(theta),0.5+0.35*sin(theta),0.0);
        glColor3f(1, 1, 1);
        glVertex3f(0.5+0.5*cos(theta),0.5+0.5*sin(theta),0.0);
    }
   
    glEnd();
    
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(r,g,b);
    glVertex3f(0.4,0.4,0.0);
    glVertex3f(0.4,0.6,0.0);
    glVertex3f(0.6,0.6,0.0);
    glVertex3f(0.6,0.4,0.0);
    glEnd();
    
    glutSwapBuffers();

}

//===== mouseClicks: handle left mouse click actions =========
void mouseClicks(int but,int sta,int x,int y){
    button = but;
    state = sta;
    
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        unsigned char pick_col[3];
        glReadPixels(x , 512-y , 1 , 1 , GL_RGB , GL_UNSIGNED_BYTE , pick_col);
        r = pick_col[0]/255.0;
        g = pick_col[1]/255.0;
        b = pick_col[2]/255.0;

    }
    
    glutPostRedisplay();
}
