#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include<windows.h>
#include<iostream>
using namespace std;

int x1,y1,x2,y2,x3,y3,x4,y4,centerx,centery,mx;

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
void dda(int x_start,int y_start,int x_end,int y_end)
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


            glVertex2d(i,Round(y_end));

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
            int x_ = (int)x_start;
            double y_ = y_start;
            while(x_<x_end)
            {

                glVertex2d(x_,Round(y_));


                x_=x_+1;
                y_=y_+m;
            }
        }
        else
        {
            int y_ = (int)y_start;
            double x_ = x_start;
            m=(1/m);
            while(y_<y_end)
            {

                glVertex2d(Round(x_),y_);

                x_=x_+m;
                y_=y_+1;
            }

        }

        glVertex2d(x_end,y_end);

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
    if(mx==1)
    {
        dda(x1,-y1,x2,-y2);
        dda(x2,-y2,x3,-y3);
        dda(x3,-y3,x4,-y4);
        dda(x4,-y4,x1,-y1);
    }
    else
    {
        dda(-x1,y1,-x2,y2);
        dda(-x2,y2,-x3,y3);
        dda(-x3,y3,-x4,y4);
        dda(-x4,y4,-x1,y1);

    }
    glEnd();
    glFlush();
}


int main(int argc,char ** argv)
{
    printf("Enter the origin of squire with length 50 pixels\n");

    scanf("%d %d",&centerx,&centery);
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
    glutCreateWindow("Translation");
    init();
    glutDisplayFunc(translation);
    glutMainLoop();
}
