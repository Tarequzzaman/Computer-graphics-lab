
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include<windows.h>

int p,q,r;

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

void mid_point_circle_drawing()
{

    int x = 0;
    int y = r;
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
     drowAxix();
    int p = 1-r;
    while(x<=y)
    {
        draw(x,y);
        if(p<0)
        {
            p=p+2*x+3;
        }
        else
        {
            p=p+2*(x-y)+5;
            y--;
        }
        x++;
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
    printf("enter  circle center p q: \n");
    scanf("%d %d",&p,&q);
    printf("enter radious circle r: \n");
    scanf("%d",&r);


    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(640,480);
    glutCreateWindow("MID POINT CIRCLE Drowing Algorithm");
    init();
    glutDisplayFunc(mid_point_circle_drawing);
    glutMainLoop();
}
