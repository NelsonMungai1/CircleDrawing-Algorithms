// adjust the projection matrix using "gluOrtho2D to center the coordinate system around the center of the window

#include <GL/glut.h>
#include<cmath>

const int width=400;
const int height=300;
int radius=4;
int x_center=3;
int y_center=3;


// bresenham Function 
void bresenhamCircle(){
    int x=0,r=radius;
    int y=r;
    int plot_x=x_center+x;
    int plot_y=y_center+y;
    int pk=3-2*r;
    // draw init point 
    glPointSize(3.0);
    glBegin(GL_POINTS);
    glVertex2i(plot_x,plot_y);
    while(x<y){
        x++;
        if(pk<0){
            pk+=4*x+6;
        }
        else{
            y--;
            pk+=4*(x-y)+10;
        }
        glVertex2i(x_center+x,y_center+y);
        glVertex2i(x_center-x,y_center+y);
        glVertex2i(x_center+x,y_center-y);
        glVertex2i(x_center-x,y_center-y);

        glVertex2i(x_center+y,y_center+x);
        glVertex2i(x_center-y,y_center+x);
        glVertex2i(x_center+y,y_center-x);
        glVertex2i(x_center-y,y_center-x);
    }
    glEnd();

}
// method to draw the diameter
void drawDiameter(){
	glColor3f(0,0,0);//color set to black
	glBegin(GL_LINES);
	glVertex2i(x_center-radius,y_center);//starting of the diameter
	glVertex2i(x_center+radius,y_center);//end of diameter
	glEnd();
}
void DrawAxix(){
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINES);
	glVertex2i(-width,0);
	glVertex2i(width,0);
	glEnd();

	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINES);
	glVertex2i(0,-height/2);
	glVertex2i(0,height/2);
	glEnd();
}
void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor4f(1.0,0.0,0.0,1.0);
	bresenhamCircle();
	drawDiameter();
	DrawAxix();
	glFlush();
}
// CALLED once to perform initialization tasks
void init(){
	glClearColor(1.0,1.0,1.0,1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	// set up 2D Orthographic viewing region centred at (width/2,height/2)
	gluOrtho2D(-100/2,100/2,-100/2,100/2);
}
// main driver function
int main(int argc,char**argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(400,400);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Mid Point Circle");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}