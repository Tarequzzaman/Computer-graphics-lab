
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
void bresenhum_circle_drawing()
{

    int x = 0;
    int y = r;
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
    drowAxix();
    int d = 3-2*r;
    while(x<=y)
    {
        draw(x,y);
        if(d<0)
        {
            d=d+4*x+6;
        }
        else
        {
            d=d+4*(x-y)+10;
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
    glutCreateWindow("Bresenham Circle Drawing :");
    init();
    glutDisplayFunc(bresenhum_circle_drawing);
    glutMainLoop();
}
