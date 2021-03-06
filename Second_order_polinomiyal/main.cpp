#include <bits/stdc++.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include<windows.h>
#define PI 3.14159265
int p,q,r;

int Round(double x)
{
    return (floor(x+0.5));
}

void draw(int a, int b)
{
   glVertex2d(a+p,b+q);
   glVertex2d(b+p,a+q);
   glVertex2d(-b+p,a+q);
   glVertex2d(-a+p,b+q);
   glVertex2d(-a+p,-b+q);
   glVertex2d(-b+p,-a+q);
   glVertex2d(b+p,-a+q);
   glVertex2d(a+p,-b+q);
}

void drowAxix()
{
   for(int i=-440;i<=480;i++)
   {
       glVertex2d(0,i);
   }
   for(int i=-520;i<=640;i++)
   {
       glVertex2d(i,0);
   }
}

void second_order_polinomiyal()
{


    int y = r;
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
    drowAxix();
    for(int x=0;x<=r;x++)
    {
        int y = Round(sqrt(r*r - x*x));
        draw(x,y);

    }
    glEnd();
    glFlush();
}

void init()
{
    glClearColor(1.0, 1.0, 1.0,0);
    glColor3f(1.0,0.0,1.0);
    gluOrtho2D(-520,640,-440,480);

}


int main(int argc,char ** argv)
{
    q = p=0;
    printf("Enter circle center of x and y\n");
    scanf("%d %d",&p,&q);
    printf("enter radious circle r: \n");
    scanf("%d",&r);


    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(640,480);
    glutCreateWindow("second_order_polinomiyal :");
    init();
    glutDisplayFunc(second_order_polinomiyal);
    glutMainLoop();
}
