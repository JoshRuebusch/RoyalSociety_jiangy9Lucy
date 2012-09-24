#include "rectangle.h"

rectangle::rectangle(){
	x1 = 0;
	y1 = 0;
	x2 = 0;
	y2 = 0;
	color = Color8u(0,0,0);
	dataArray = NULL;
	z = 0.0f;
}

void rectangle::setRectangle(uint8_t* dataArray_new, int x1_new, int y1_new, int x2_new, int y2_new,float z_new, Color8u color_new){
	dataArray = dataArray_new;
	x1 = x1_new;
	y1 = y1_new;
	x2 = x2_new;
	y2 = y2_new;
	color = color_new;
	z = z_new;
}

void rectangle::draw(){
	for(int x=0; x<=windowWidth; x++){
		for(int y=0; y<=windowHeight; y++){
			if(x>x1 && x<x2 && y>y1 && y<y2){
					dataArray[4*(x + y * windowWidth)] = color.r;
					dataArray[4*(x + y * windowWidth)+1] = color.g;
					dataArray[4*(x + y * windowWidth)+2] = color.b;
					dataArray[4*(x + y * windowWidth)+3] = 255*z;
			}
		}
	}
}