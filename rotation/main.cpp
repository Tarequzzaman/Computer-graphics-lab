#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include<windows.h>
#include<iostream>
#define PI 3.14159265
using namespace std;

int x1,y1,x2,y2,x3,y3,x4,y4,centerx,centery;
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
void original(int x ,int y)
{
    x1 = x;
    y1 = y;
    x2 = x;
    y2 = y+50;
    x3 = x+50;
    y3 = y+50;
    x4 = x+50;
    y4 = y;
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
void translation()
{
    original(centerx,centery);
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
    drowAxix();
    glEnd();
    glFlush();

    glColor3f(0.0,0.0,1.0);
    glBegin(GL_POINTS);
    dda(x1,y1,x2,y2);
    dda(x2,y2,x3,y3);
    dda(x3,y3,x4,y4);
    dda(x4,y4,x1,y1);
    glEnd();
    glFlush();

    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POINTS);

    dda((x1*cos(rt)-y1*sin(rt)),(x1*sin(rt)+y1*cos(rt)), (x2*cos(rt)-y2*sin(rt)),(x2*sin(rt)+y2*cos(rt)));
    dda((x2*cos(rt)-y2*sin(rt)),(x2*sin(rt)+y2*cos(rt)), (x3*cos(rt)-y3*sin(rt)),(x3*sin(rt)+y3*cos(rt)));
    dda((x3*cos(rt)-y3*sin(rt)),(x3*sin(rt)+y3*cos(rt)), (x4*cos(rt)-y4*sin(rt)),(x4*sin(rt)+y4*cos(rt)));
    dda((x4*cos(rt)-y4*sin(rt)),(x4*sin(rt)+y4*cos(rt)), (x1*cos(rt)-y1*sin(rt)),(x1*sin(rt)+y1*cos(rt)));
    glEnd();
    glFlush();
}


int main(int argc,char ** argv)
{
    printf("Enter the origin of squire with length 50 pixels\n");
    scanf("%d %d",&centerx,&centery);
    printf("Enter the angle for Rotation\n");
    scanf("%lf",&rt);
    rt =   (PI / 180)*rt;
    glutInit(&argc,argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(640,480);
    glutCreateWindow("Translation");
    init();
    glutDisplayFunc(translation);
    glutMainLoop();
}
