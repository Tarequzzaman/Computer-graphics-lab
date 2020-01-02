#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include<windows.h>
#include<iostream>
using namespace std;

double x_start,y_start,x_end,y_end;

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
void dda()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
    drowAxix();
    if(x_start == x_end)
    {
        double y_min = y_start < y_end ? y_start : y_end;
        double y_max = y_start < y_end ? y_end  :y_start;
        for(int i = (int)y_min ; i<=(int)y_max; i++)
        {
            glBegin(GL_POINTS);
            glVertex2d(x_start,i);
            glEnd();
            glFlush();
        }

    }
    else if(y_start==y_end)
    {

        double x_min = x_start < x_end ? x_start : x_end;
        double x_max = x_start < x_end ? x_end : x_start;
        for(int i = (int)x_min ; i<=(int)x_max; i++)
        {

            glBegin(GL_POINTS);
            glVertex2d(i,Round(y_end));
            glEnd();
            glFlush();
        }
    }
    else
    {
        if(x_start > x_end)
        {
            double temp = x_start;
            x_start = x_end;
            x_end = temp;
            temp = y_start;
            y_start =y_end;
            y_end = temp;
        }
        double m = (y_end-y_start)/(x_end-x_start);
        if(m <1)
        {
            int x = (int)x_start;
            double y = y_start;
            while(x<x_end)
            {
                glBegin(GL_POINTS);
                glVertex2d(x,Round(y));
                glEnd();
                glFlush();

                x=x+1;
                y=y+m;
            }
        }
        else
        {
            int y = (int)y_start;
            double x = x_start;
            m=(1/m);
            while(y<y_end)
            {
                glBegin(GL_POINTS);
                glVertex2d(Round(x),y);
                glEnd();
                glFlush();
                x=x+m;
                y=y+1;
            }

        }
        glBegin(GL_POINTS);
        glVertex2d(x_end,y_end);
        glEnd();
        glFlush();
    }

}

void init()
{
    glClearColor(1.0, 1.0, 1.0,0);
    glColor3f(0.0,0.0,0.0);
    gluOrtho2D(-520,640,-440,480);
}


int main(int argc,char ** argv)
{

    printf("ENTER x_start y_start: \n");
    scanf("%lf %lf",&x_start,&y_start);
    printf("ENter x_end y_end: \n");
    scanf("%lf %lf",&x_end,&y_end);
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(640,480);
    glutCreateWindow("DDA");
    init();
    glutDisplayFunc(dda);
    glutMainLoop();
}
