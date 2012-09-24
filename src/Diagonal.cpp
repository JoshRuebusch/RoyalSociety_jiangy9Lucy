#include "Diagonal.h"

Diagonal::Diagonal(){
	dataArray = NULL;
	x1 = 0;
	y1 = 0;
	x2 = 0;
	y2 = 0;
	color = Color8u(0,0,0);
}

void Diagonal::set(uint8_t* dataArray_new, int x1_new, int y1_new, int x2_new, int y2_new, Color8u color_new){
	dataArray = dataArray_new;
	x1 = x1_new;
	y1 = y1_new;
	x2 = x2_new;
	y2 = y2_new;
	color = color_new;
}

void Diagonal::draw(){
	if(x1 < x2 && y1 < y2){
		int x = x1;
		int y = y1;
		while(x <= x2 && y <= y2){
			dataArray[4 * (x + y * windowWidth)] = color.r;
			dataArray[4 * (x + y * windowWidth)+1] = color.g;
			dataArray[4 * (x + y * windowWidth)+2] = color.b;
			dataArray[4 * (x + y * windowWidth)+3] = 255;
			x++;
			y++;
		}
	}
	else{
		int x = x1;
		int y = y1;
		while(x <= x2 && y >= y2){
			dataArray[4 * (x + y * windowWidth)] = color.r;
			dataArray[4 * (x + y * windowWidth)+1] = color.g;
			dataArray[4 * (x + y * windowWidth)+2] = color.b;
			dataArray[4 * (x + y * windowWidth)+3] = 255;
			x++;
			y--;
		}
	}
}