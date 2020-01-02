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
void Brasenhum_line_drawing()
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
        double x_max = x_start < x_end ? x_end  :x_start;
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
        int dx = abs(x_end - x_start);
        int dy = abs(y_end - y_start);

        if (dx >= dy)
        {
            double i, j, k;
            i = 2 * dy - dx;
            j = 2 * dy;
            k = 2 * (dy - dx);
            if (!(x_start < x_end))
            {
                swap(x_start, x_end);
                swap(y_start, y_end);
            }
            glBegin(GL_POINTS);

            glVertex2d(x_start,y_start);
            glEnd();
            glFlush();
            while (x_start < x_end)
            {
                if (i < 0)
                    i += j;
                else
                {
                    if (y_start < y_end)
                        ++y_start;
                    else
                        --y_start;
                    i += k;
                }
                ++x_start;

                glBegin(GL_POINTS);

                glVertex2d(x_start,y_start);
                glEnd();
                glFlush();
            }
        }

        else
        {

            double i, j, k;

            i = 2 * dx - dy;
            j = 2 * dx;
            k = 2 * (dx - dy);
            if (!(y_start < y_end))
            {
                swap(x_start, x_end);
                swap(y_start, y_end);
            }
            glBegin(GL_POINTS);

            glVertex2d(x_start,y_start);
            glEnd();
            glFlush();
            while (y_start < y_end)
            {
                if (i < 0)
                    i += j;
                else
                {
                    if (x_start > x_end)
                        --x_start;
                    else
                        ++x_start;
                    i += k;
                }
                ++y_start;
                glBegin(GL_POINTS);

                glVertex2d(x_start,y_start);
                glEnd();
                glFlush();
            }
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
    glutCreateWindow("Brasenham line drawing");
    init();
    glutDisplayFunc(Brasenhum_line_drawing);
    glutMainLoop();
}
