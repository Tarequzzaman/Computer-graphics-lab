#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include<windows.h>
#include<algorithm>
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
void Direct_Line()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
    drowAxix();
    glEnd();
    glFlush();
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
            glVertex2d(i,y_end);
            glEnd();
            glFlush();
        }
    }
    else
    {
        if(x_end <x_start)
        {
            swap(x_start,x_end);
            swap(y_start,y_end);
        }
        double dx=x_end-x_start;
        double dy=y_end-y_start;
        double m=(dy/dx);
        double x=x_start,y=y_start;
        double b=y_start-(m*x_start);
        while(x_start <=x_end)
        {
            glBegin(GL_POINTS);
            glVertex2d(x_start,y_start);
            glEnd();
            glFlush();
            x_start=x_start+1;
            y_start = m*x_start + b;

        }


    }

}

void init()
{
    glClearColor(1.0, 1.0, 1.0,0);
    glColor3f(1.0,0.0,0.0);
    gluOrtho2D(-520,640,-440,480);

}

int main(int argc,char ** argv)
{

    printf("x_start y_start: \n");
    scanf("%lf %lf",&x_start,&y_start);
    printf("ENTER x_end y_end: \n");
    scanf("%lf %lf",&x_end,&y_end);


    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(640,480);
    glutCreateWindow("Direct line drawing");
    init();
    glutDisplayFunc(Direct_Line);

    glutMainLoop();
}
