// adjust the projection matrix using "gluOrtho2D to center the coordinate system around the center of the window

# include <GL/glut.h>
#include<cmath>

const int width=400;
const int height=300;
int radius=4;
int x_center=3;
int y_center=3;

void midPointCircleDraw(){
	int initPoint_x=0,init_point_y=radius;
	int new_x=initPoint_x,new_y=init_point_y;
	int plot_x=x_center+initPoint_x;
	int plot_y=y_center+init_point_y;

	int pk=1-radius;
// Increase point size
	glPointSize(3.0);

	glBegin(GL_POINTS);
	glVertex2i(plot_x,plot_y);
	while(new_x<new_y){
		new_x++;
		if(pk<0){
			pk+=2*new_x+1;
		}else{
			new_y--;
			pk=pk+2*(new_x-new_y)+1;
		}
		glVertex2i(x_center+new_x,y_center+new_y);
		glVertex2i(x_center-new_x,y_center+new_y);
		glVertex2i(x_center+new_x,y_center-new_y);
		glVertex2i(x_center-new_x,y_center-new_y);
		glVertex2i(x_center+new_y,y_center+new_x);
		glVertex2i(x_center-new_y,y_center+new_x);
		glVertex2i(x_center+new_y,y_center-new_x);
		glVertex2i(x_center-new_y,y_center-new_x);


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
void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor4f(1.0,0.0,0.0,1.0);
	midPointCircleDraw();
	drawDiameter();
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
	glutInitWindowSize(100,100);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Mid Point Circle");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}