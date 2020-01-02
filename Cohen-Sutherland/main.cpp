#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include<windows.h>
#include<iostream>
using namespace std;

int wx1,wx2,wy1,wy2,line_no;
struct points
{
    int x_start;
    int y_start;
    int x_end;
    int y_end;
    int visible;
};
points line_arr[100];
int visible_test(int x,int y)
{

    int res=0;

    if(x < wx1)
    {
        res+=1;
    }
    if(x > wx2)
    {
        res+=2;
    }
    if(y < wy1)
    {
        res+=4;
    }
    if(y > wy2)
    {
        res+=8;
    }
    return res;
}


int Round(double x)
{
    return (floor(x+0.5));
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
    glBegin(GL_POINTS);
    glVertex2d(x_,y_);
    glEnd();
    glFlush();
    int k;

    /* For every step, find an intermediate vertex */

    for(k=0; k<steps; k++)
    {
        x_+=xInc;
        y_+=yInc;
        /* printf("%0.6lf %0.6lf\n",floor(x), floor(y)); */
        glBegin(GL_POINTS);
        glVertex2d(Round(x_), Round(y_));
        glEnd();
        glFlush();
    }
}

void dda1(double x_start, double y_start, double x_end,double y_end)
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

    int k;

    /* For every step, find an intermediate vertex */

    for(k=0; k<steps; k++)
    {

        /* printf("%0.6lf %0.6lf\n",floor(x), floor(y)); */
        int xx = round(x_);
        int yy = round(y_);
        int a = visible_test(xx,yy);
        if(a!=0)
        {
            glBegin(GL_POINTS);
            glVertex2d(xx, yy);
            glEnd();
            glFlush();
        }
        x_+=xInc;
        y_+=yInc;
    }
}

void init()
{
    glClearColor(1.0, 1.0, 1.0,0);
    glColor3f(0.0,0.0,0.0);
    gluOrtho2D(-520,640,-440,480);
}

void input()
{
    printf("Enter the window co-ordinate x_min and x_max\n");
    scanf("%d %d",&wx1,&wy1);
    printf("Enter the window co-ordinate x_min and x_max\n");
    while(true)
    {
        scanf("%d %d",&wx2,&wy2);
        if(wx1>=wx2 || wy1>=wy2)
        {
            printf("Enter valid end points\n");
        }
        else
        {
            break;
        }
    }

    printf("How many line\n");
    scanf("%d",&line_no);
    printf("x1 y1 x2 y2\n");
    for(int i=0; i<line_no; i++)
    {
        scanf("%d %d",&line_arr[i].x_start, &line_arr[i].y_start);

        int a = visible_test(line_arr[i].x_start,line_arr[i].y_start);

        scanf("%d %d",&line_arr[i].x_end, &line_arr[i].y_end);

        int b = visible_test(line_arr[i].x_end,line_arr[i].y_end);

        int p = a&b;
        if(a==0 && b==0)
        {
            line_arr[i].visible = 2;
        }
        else if(p==0)
        {
            line_arr[i].visible = 1;
        }
        else
        {
            line_arr[i].visible = 0;
        }
    }
}
void line_clip()
{
    glClear(GL_COLOR_BUFFER_BIT);

    dda(wx1,wy1,wx1,wy2);
    dda(wx1,wy2,wx2,wy2);
    dda(wx2,wy2,wx2,wy1);
    dda(wx2,wy1,wx1,wy1);


    for(int i=0; i<line_no; i++)
    {
        if(line_arr[i].visible==0)
        {
            glColor3f(1.0,0.0,0.0);

            dda(line_arr[i].x_start,line_arr[i].y_start,line_arr[i].x_end,line_arr[i].y_end);

        }
        else  if(line_arr[i].visible==1)
        {
            glColor3f(0.0,0.0,1.0);

            dda(line_arr[i].x_start,line_arr[i].y_start,line_arr[i].x_end,line_arr[i].y_end);

        }
        else
        {
            glColor3f(0.0,1.0,0.0);

            dda(line_arr[i].x_start,line_arr[i].y_start,line_arr[i].x_end,line_arr[i].y_end);

        }
    }

    for(int i=0; i<50000; i++)
    {
        for(int j=0; j<5000; j++)
        {

        }
    }

    for(int i=0; i<line_no; i++)
    {
        if(line_arr[i].visible==0)
        {
            glColor3f(1.0,1.0,1.0);

            dda(line_arr[i].x_start,line_arr[i].y_start,line_arr[i].x_end,line_arr[i].y_end);

        }
    }

    for(int i=0; i<line_no; i++)
    {
        if(line_arr[i].visible==1)
        {
            glColor3f(1.0,1.0,1.0);

            dda1(line_arr[i].x_start,line_arr[i].y_start,line_arr[i].x_end,line_arr[i].y_end);
        }
    }


}

int main(int argc,char ** argv)
{

    glutInit(&argc,argv);
    input();
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(640,480);
    glutCreateWindow("Cohen-Sutherland Line Clipping");
    init();
    glutDisplayFunc(line_clip);
    glutMainLoop();
}
