#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include<windows.h>
#include<vector>
#include<algorithm>
#include <bits/stdc++.h>
#define INF -999999
#define SIZE 9999999
using namespace std;
int x[4] = {-1,0,1,0};
int y[4] = {0,1,0,-1};
int seedx,seedy;
int cou =0,v=0;
struct node
{
    double x_cor;
    double y_cor;
} extra;

node arr[SIZE];
struct edge
{
    double x1;
    double y1;
    double x2;
    double y2;  /// edge array
    double _1_m;
    double y_min;
    double x_min;
    double y_max;
};

edge edge_table[SIZE];

struct collect
{
    int x,y;
    int visit;
};
collect collection[SIZE],visiting[SIZE];


int vertex,up_vertex=0;

int Round(double x)
{
    return (floor(x+0.5));
}

bool comphere(collect a, collect b)
{
    return (a.y < b.y);
}
int inside_outside_test(int sx,int sy)
{
    int l=0,r=0;
    int sp = sx;
    for(int i=0; i<500; i++)
    {

        for(int j=0; j<cou; j++)
        {
            if(collection[j].y == sy && collection[j].x == sx)
            {
                l++;
            }
        }
        sx=sx+1;
    }
    sx=sp;
    for(int i=0; i<500; i++)
    {

        for(int j=0; j<cou; j++)
        {
            if(collection[j].y == sy && collection[j].x == sx)
            {
                r++;
            }
        }
        sx= sx-1;
    }

    if(l%2==1 && r%2==1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void drowAxix()
{
    glBegin(GL_POINTS);
    for(int i=-440; i<=480; i++)
    {
        glVertex2d(0,i);
    }
    for(int i=-520; i<=640; i++)
    {
        glVertex2d(i,0);
    }

    glEnd();
    glFlush();
}

int visiting_test(int sx,int sy)
{

    for(int i=0; i<v; i++)
    {
        if(visiting[i].x==sx && visiting[i].y==sy)
        {
            return 1;
        }
    }
    return 0;
}
void init()
{

    glClearColor(1.0, 1.0, 1.0,0);
    glColor3f(0.0,1.0,0.0);
    gluOrtho2D(-520,640,-440,480);
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
}

void scan()
{
    for(int i=0; i<vertex; i++)
    {
        scanf("%lf %lf",&arr[i].x_cor,&arr[i].y_cor);///Scaning the vertex
    }
}

void  slope_calculete()
{

    for(int i=0; i<vertex; i++)
    {
        int j=i+1;
        if(j==vertex)
        {
            j=0;
        }
        edge_table[i].x1 = arr[i].x_cor;
        edge_table[i].y1 = arr[i].y_cor;
        edge_table[i].y2 = arr[j].y_cor;
        edge_table[i].x2 = arr[j].x_cor;


        float dx = (arr[j].x_cor - arr[i].x_cor);
        float dy = (arr[j].y_cor - arr[i].y_cor);

        if(dy==0)
        {
            edge_table[i]._1_m = 1;
        }
        else if(dx==0)
        {
            edge_table[i]._1_m = 0;
        }

        if(dx!=0 && dy!=0)
        {
            edge_table[i]._1_m = (float) dx/dy;
        }
    }
}
void split()
{
    int j=1;
    int k=2;
    for(int i=0; i<vertex; i++)
    {

        if(j ==vertex)
        {
            j=0;
        }
        if(k ==vertex)
        {
            k=0;
        }
        if(arr[i].y_cor < arr[j].y_cor && arr[j].y_cor < arr[k].y_cor) ///split
        {

            edge_table[i].x2 = Round((arr[i].x_cor + edge_table[i]._1_m * (arr[j].y_cor-1-arr[i].y_cor)));
            edge_table[i].y2 = edge_table[i].y2 -1;
            edge_table[i].y_max = (edge_table[i].y1 > edge_table[i].y2) ? edge_table[i].y1 :edge_table[i].y2;
            if(edge_table[i].y1 < edge_table[i].y2)
            {
                edge_table[i].y_min = edge_table[i].y1 ;
                edge_table[i].x_min = edge_table[i].x1;
            }
            else
            {
                edge_table[i].y_min = edge_table[i].y2 ;
                edge_table[i].x_min = edge_table[i].x2;
            }


        }
        else if(arr[i].y_cor > arr[j].y_cor && arr[j].y_cor > arr[k].y_cor)/// split
        {
            edge_table[j].x1 = Round((arr[k].x_cor + edge_table[j]._1_m * (arr[j].y_cor-1-arr[k].y_cor)));
            edge_table[j].y1 = edge_table[i].y2 -1;

            edge_table[i].y_max = (edge_table[i].y1 > edge_table[i].y2) ? edge_table[i].y1 : edge_table[i].y2;

            if(edge_table[i].y1 < edge_table[i].y2)
            {
                edge_table[i].y_min = edge_table[i].y1 ;
                edge_table[i].x_min = edge_table[i].x1;
            }
            else
            {
                edge_table[i].y_min = edge_table[i].y2 ;
                edge_table[i].x_min = edge_table[i].x2;
            }
        }
        else
        {
            edge_table[i].y_max = (edge_table[i].y1 > edge_table[i].y2) ? edge_table[i].y1 : edge_table[i].y2;
            if(edge_table[i].y1 < edge_table[i].y2)
            {
                edge_table[i].y_min = edge_table[i].y1;
                edge_table[i].x_min = edge_table[i].x1;
            }
            else
            {
                edge_table[i].y_min = edge_table[i].y2 ;
                edge_table[i].x_min = edge_table[i].x2;
            }
        }

        j=j+1;
        k=k+1;

    }

    for(int i=0; i<vertex; i++)
    {
        int y_min = (int) edge_table[i].y_min;
        int x_min = (int) edge_table[i].x_min;
        int y_max = (int) edge_table[i].y_max;
        double slope = edge_table[i]._1_m;
        double m = x_min;
        for(int j=y_min; j<=y_max; j++)
        {
            collection[cou].x = x_min;
            collection[cou].y = j;
            collection[cou].visit =0;
            m = slope + m;
            x_min = Round(m);
            cou++;
        }
    }

}

void draw_polygon()
{
    glColor3f(1.0,0.0,0.0);
    for(int i=0; i<cou ; i++)
    {
        glBegin(GL_POINTS);
        glVertex2d(collection[i].x,collection[i].y);
        glEnd();
        glFlush();
    }
}

void fill_four_connect()
{
    queue<int> q;
    q.push(seedx);
    q.push(seedy);
    visiting[v].x = seedx;
    visiting[v].y = seedy;
    v++;
    while(!q.empty())
    {
        int ux = q.front();
        q.pop();
        int uy = q.front();
        q.pop();
        glColor3f(1.0,0.0,1.0);
        glBegin(GL_POINTS);
        glVertex2d(ux,uy);
        glEnd();
        glFlush();
        for(int i=0; i<4; i++)
        {
            int  vx = ux + x[i];
            int vy = uy + y[i];
            int check_visit = visiting_test(vx,vy);
            if(check_visit == 0)
            {
                int check_point = inside_outside_test(vx,vy);
                if(check_point%2==1)
                {
                    visiting[v].x = vx;
                    visiting[v].y = vy;
                    v++;
                    q.push(vx);
                    q.push(vy);
                }
            }
        }
    }
}
void get_seedpoints()
{
    printf("Enter The Seed Point\n");
    int res=0;
    while(res%2==0)
    {
        scanf("%d %d",&seedx,&seedy);
        int res =  inside_outside_test(seedx,seedy);
        if(res%2==0)
        {
            printf("The point you enter is outside the boundary\n");
        }
        else
        {
            break;
        }
    }
}
void polygon_draw()
{
    drowAxix();
    draw_polygon();
    fill_four_connect();
}
int main(int argc,char ** argv)
{
    printf("Enter Numbers of Node :\n" );
    scanf("%d",&vertex);
    printf("Enter x and y co-ordinate :\n"  );
    scan();
    slope_calculete();
    split();
    get_seedpoints();
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(640,480);
    glutCreateWindow("Polygon Filling Algorithm Scan Line");
    init();
    glutDisplayFunc(polygon_draw);
    glutMainLoop();
}


/*
4
-75 10
85 85
-10 -75
25 25
*/
