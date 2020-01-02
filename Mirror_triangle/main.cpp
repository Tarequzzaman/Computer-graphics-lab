#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include<windows.h>
#include<iostream>
#define PI 3.14159265
using namespace std;

int a,b,c,d,e,f,h,k,mx;

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
void Direct_Line(double x_start, double y_start, double x_end,double y_end)
{

    if(x_start == x_end)
    {
        double y_min = y_start < y_end ? y_start : y_end;
        double y_max = y_start < y_end ? y_end  :y_start;
        for(int i = (int)y_min ; i<=(int)y_max; i++)
        {

            glVertex2d(x_start,i);

        }

    }
    else if(y_start==y_end)
    {
        double x_min = x_start < x_end ? x_start : x_end;
        double x_max = x_start < x_end ? x_end : x_start;
        for(int i = (int)x_min ; i<=(int)x_max; i++)
        {

            glVertex2d(i,y_end);

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
        double b=y_start-(m*x_start);
        while(x_start <=x_end)
        {

            glVertex2d(x_start,y_start);

            x_start=x_start+1;
            y_start = m*x_start + b;

        }


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
    Direct_Line(a,b,c,d);
    Direct_Line(c,d,e,f);
    Direct_Line(e,f,a,b);
    glEnd();
    glFlush();

    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POINTS);

    if(mx==1)
    {
        b = -b;
        d = -d;
        f = -f;
        Direct_Line(a,b,c,d);
        Direct_Line(c,d,e,f);
        Direct_Line(e,f,a,b);
    }
    else
    {
        a = -a ;
        c = -c ;
        e = -e ;
        Direct_Line(a,b,c,d);
        Direct_Line(c,d,e,f);
        Direct_Line(e,f,a,b);
    }
    glEnd();
    glFlush();
}


int main(int argc,char ** argv)
{
    printf("Enter the points of triangle\n");
    scanf("%d %d",&a,&b);
    scanf("%d %d",&c,&d);
    scanf("%d %d",&e,&f);
    printf("choose a 1 for mirror about x- axis and 2 for y axis\n");
    while(true)
    {

        scanf("%d",&mx);
        if(mx==1|| mx==2)
        {

            break;
        }
        else
        {

            printf("Chose 1 or 2\n");
        }
    }

    glutInit(&argc,argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(640,480);
    glutCreateWindow("Mirror");
    init();
    glutDisplayFunc(rotation_arbitary);
    glutMainLoop();
    /**
    Tarequzzaman Khan
    CSE'12
    Reg: 2012331514
    */
}
