// C++ program for implementing
// Mid-Point Circle Drawing Algorithm
#include<iostream>
using namespace std;

// Implementing Mid-Point Circle Drawing Algorithm
void midPointCircleDraw(int x_centre, int y_centre, int r)
{
    // intializing the point x and y to (0,r)
    int init_point_x=0,init_point_y=r;
    int new_x,new_y;
    // setting the plot values for x and y
    int plot_x=x_centre+init_point_x;
    int plot_y=y_centre+init_point_y;
    int pk=1-r;
    cout <<"pk"<<pk<<endl;
    while(plot_y>plot_x){
        if (pk<0){
            pk=pk+2*new_x+3;
            new_x+=1;
            new_y=new_y;
            plot_x+=1,plot_y=plot_y;
            cout <<"new_x:"<<plot_x<<"new_y:"<<plot_y<<"PK: "<<pk<<endl;
            
        }
        else if(pk>=0){
            pk=pk+2*(new_x-new_y)+5;
            new_x+=1;
            new_y-=1;
            plot_x+=1,plot_y-=1;
            cout <<"new_x:"<<plot_x<<"new_y:"<<plot_y<<"PK: "<<pk<<endl;
        }
        
    }

}

// Driver code
void DrawMidPointCircle(){
    
}
int main()
{
	// To draw a circle of radius 3 centered at (0, 0)
	midPointCircleDraw(0, 0, 8);
	return 0;
}
