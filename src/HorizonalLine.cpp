#include "HorizonalLine.h"

HorizonalLine::HorizonalLine(){
	dataArray = NULL;
	x1 = 0;
	x2 = 0;
	y = 0;
	color = Color8u(0,0,0);
}

void HorizonalLine::set(uint8_t* dataArray_new, int x1_new, int x2_new, int y_new, Color8u color_new){
	dataArray = dataArray_new;
	x1 = x1_new;
	x2 = x2_new;
	y = y_new;
	color = color_new;
}

void HorizonalLine::draw(){
	for(int draw = x1; draw <= x2; draw++){
		for(int count = y-5; count <= y+5; count++){
			dataArray[4*(draw + count * windowWidth)] = color.r;
			dataArray[4*(draw + count * windowWidth)+1] = color.g;
			dataArray[4*(draw + count * windowWidth)+2] = color.b;
			dataArray[4*(draw + count * windowWidth)+3] = 255;
		}
	}
}