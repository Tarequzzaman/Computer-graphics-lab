#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include<windows.h>
#include<iostream>
using namespace std;

int x1,y1,x2,y2,x3,y3,x4,y4,centerx,centery,a,b;

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
    if(b==0)
    {
        dda((x1+a*y1),y1,(x2+a*y2),y2);
        dda(x2+a*y2,y2,x3+a*y3,y3);
        dda((x3+a*y3),y3,(x4+a*y4),y4);
        dda(x4+a*y4,y4,x1+a*y1,y1);
    }
    else if(a==0)
    {
        dda(x1,y1+b*x1,x2,y2+b*x2);
        dda(x2,y2+b*x2,x3,y3+b*x3);
        dda(x3,y3+b*x3,x4,y4+b*x4);
        dda(x4,y4+b*x4,x1,y1+b*x1);
    }
    else
    {
        dda(x1+a*y1,y1+b*x1,x2+a*y2,y2+b*x2);
        dda(x2+a*y2,y2+b*x2,x3+a*y3,y3+b*x3);
        dda(x3+a*y3,y3+b*x3,x4+a*y4,y4+b*x4);
        dda(x4+a*y4,y4+b*x4,x1+a*y1,y1+b*x1);
    }
    glEnd();
    glFlush();
}


int main(int argc,char ** argv)
{
    printf("Enter the origin of squire with length 50 pixels\n");

    scanf("%d %d",&centerx,&centery);
    printf("Enter the shearing factor a and b\n");
    scanf("%d %d",&a,&b);
    glutInit(&argc,argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(640,480);
    glutCreateWindow("Translation");
    init();
    glutDisplayFunc(translation);
    glutMainLoop();
}
