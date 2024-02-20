#include <iostream>
#include <GL/glut.h>
using namespace std;
int y_radius=6,x_radius=8;
int x_center=0,_y_center=0;

void plotEllipse(int x,int y){
    glBegin(GL_POINTS);
    glVertex2i(x_center+x,_y_center+y);
    glVertex2i(x_center-x,_y_center+y);
    glVertex2i(x_center+x,_y_center-y);
    glVertex2i(x_center-x,_y_center-y);
    glEnd();
}

void midPointEllipse(int rx,int ry,int xc,int yc){
    int dx,dy,p1,p2;
    int x=0;
    int y=y_radius;
    int plot_x=x_center+x;
    int plot_y=_y_center+y;

    dy=2*rx*rx*y;
    dx=2*ry*ry*x;
    p1=(ry*ry)-(rx*rx*ry)+(0.25*rx*rx);
    glPointSize(3.0);
    glBegin(GL_POINTS);
    // for octant 1
    glVertex2i(plot_x,plot_y);
    while(dx<dy){
        plotEllipse(x,y);
        cout << x_center+x << " , " <<_y_center+y << endl;
        cout << x_center-x << " , " << _y_center+y << endl;
        cout << x_center+x << " , " << _y_center-y << endl;
        cout << x_center-x << " , " << _y_center-y << endl;

        cout << x_center+y << " , " <<_y_center+x << endl;
        cout << x_center-y << " , " << _y_center+x << endl;
        cout << x_center+y << " , " << _y_center-x << endl;
        cout << x_center-y << " , " << _y_center-x << endl;

        // updates based on decision parameter
        if(p1<0){
            x++;
            dx=dx+(2*ry*ry);
            p1=p1+dx+(ry*ry);
        }
        else{
            x++;
            y--;
            dx=dx+(2*ry*ry);
            dy=dy-(2*rx*rx);
            p1=p1+dx-dy+(ry*ry);
        }
    }
    // for octant 2
    p2=ry*ry*(((x+0.5)*(x+0.5)))+
    ((rx*rx)*(y-1)*(y-1))-
    ((ry*ry)*(rx*rx));

    while(y>=0){
        plotEllipse(x,y);
        if(p2>0){
            y--;
            dy=dy-(2*rx*rx);
            p2=p2+(rx*rx)-dy;
        }
        else{
            y--;
            x++;
            dx = dx + (2 * ry * ry);
            dy = dy - (2 * rx * rx);
            p2 = p2 + dx - dy + (rx * rx);
        }
    }
}
void DrawAxes(){
    glColor3f(0,0,0);
    glBegin(GL_LINES);
    glVertex2i(-20,0);
    glVertex2i(20,0);
    glEnd();

    glColor3f(0,0,0);
    glBegin(GL_LINES);
    glVertex2i(0,-20);
    glVertex2i(0,20);
    glEnd();
}
void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,1.0,0.0);//set color to green for the plots
    midPointEllipse(x_radius,y_radius,x_center,_y_center);
    DrawAxes();
    glFlush();
}
void init(){
    glClearColor(1.0,1.0,1.0,1.0);//back ground set to white
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-20,20,-20,20);
}
int main(int argc, char **argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400,400);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Mid Point Ellipse");
    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}