#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include<windows.h>
#include<iostream>
#define PI 3.14159265
using namespace std;

int a,b,c,d,e,f,h,k,val;

double rt;
int Round(double x)
{
    return (floor(x+0.5));
}


void drowAxix()
{
    for(int i=-440; i<=480; i++)
    {
        glVertex2d(0,i);
    }
    for(int i=-520; i<=640; i++)
    {
        glVertex2d(i,0);
    }
}
void init()
{
    glClearColor(1.0, 1.0, 1.0,0);
    glColor3f(0.0,0.0,0.0);
    gluOrtho2D(-520,640,-440,480);
}


void dda(double x_start, double y_start, double x_end,double y_end)
{
    double dx=(x_end-x_start);
    double dy=(y_end-y_start);
    double steps;
    float xInc,yInc,x_=x_start,y_=y_start;

    /* Find out whether to increment x or y */
    steps= max(abs(dx),abs(dy));

    xInc=dx/(float)steps;
    yInc=dy/(float)steps;



    /* Plot the first point */
    glVertex2d(x_,y_);
    int k;

    /* For every step, find an intermediate vertex */

    for(k=0; k<steps; k++)
    {
        x_+=xInc;
        y_+=yInc;
        /* printf("%0.6lf %0.6lf\n",floor(x), floor(y)); */
        glVertex2d(Round(x_), Round(y_));
    }
}

void rotation_arbitary()
{

    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
    drowAxix();
    glEnd();
    glFlush();

    glColor3f(0.0,0.0,1.0);
    glBegin(GL_POINTS);
    dda(a,b,c,d);
    dda(c,d,e,f);
    dda(e,f,a,b);
    glEnd();
    glFlush();

    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POINTS);
    double a1 = a*cos(rt) - b*sin(rt) + (-h*cos(rt)+k*sin(rt)+h);
    double c1 = c*cos(rt) - d*sin(rt) + (-h*cos(rt)+k*sin(rt)+h);
    double e1 = e*cos(rt) - f*sin(rt) + (-h*cos(rt)+k*sin(rt)+h);

    double b1 = a*sin(rt)+b* cos(rt) + (-h*sin(rt)-k*cos(rt)+h);
    double d1 = c*sin(rt)+d* cos(rt) + (-h*sin(rt)-k*cos(rt)+h);
    double f1 = e*sin(rt)+f* cos(rt) + (-h*sin(rt)-k*cos(rt)+h);

    dda(a1,b1,c1,d1);
    dda(c1,d1,e1,f1);
    dda(e1,f1,a1,b1);

    glEnd();
    glFlush();
}


int main(int argc,char ** argv)
{
    printf("Enter the points of triangle\n");
    scanf("%d %d",&a,&b);
    scanf("%d %d",&c,&d);
    scanf("%d %d",&e,&f);
    printf("Enter the arbitary point\n");
    scanf("%d %d",&h,&k);
    printf("Enter the angle of Rotation\n");
    scanf("%d",&val);
    rt = (PI / 180)*val;
    glutInit(&argc,argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(640,480);
    glutCreateWindow("Translation");
    init();
    glutDisplayFunc(rotation_arbitary);
    glutMainLoop();
    /**
    Tarequzzaman Khan
    CSE'12
    2012331514
    */
}
