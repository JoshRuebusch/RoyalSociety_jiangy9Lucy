#include "Flower.h"

Flower::Flower(){
	center_x = 0.0f;
	center_y = 0.0f;
	Color8u color = Color8u(0,0,0);
	dataArray = NULL;
}

void Flower::set(uint8_t* dataArray_new, float center_x_new, float center_y_new, Color8u color_new){
	dataArray = dataArray_new;
	center_x = center_x_new;
	center_y = center_y_new;
	color = color_new;
}

void Flower::draw(){
	for(int y=0; y<=windowHeight; y++){
		for(int x=0;x<=windowWidth; x++){
			if ((x-center_x)*(x-center_x) + (y-center_y)*(y-center_y) <= (30.0f*30.0f)){
				dataArray[4*(x + y * windowWidth)] = color.r;
				dataArray[4*(x + y * windowWidth)+1] = color.g;
				dataArray[4*(x + y * windowWidth)+2] = color.b;
				dataArray[4*(x + y * windowWidth)+3] = 255;
			}
		}
	}

	for(int y=0; y<=windowHeight; y++){
		for(int x=0;x<=windowWidth; x++){
			if ((x-center_x)*(x-center_x) + (y-(center_y-37.0f))*(y-(center_y-37.0f)) <= (30.0f*30.0f)){
				dataArray[4*(x + y * windowWidth)] = color.r;
				dataArray[4*(x + y * windowWidth)+1] = color.g;
				dataArray[4*(x + y * windowWidth)+2] = color.b;
				dataArray[4*(x + y * windowWidth)+3] = 255;
			}
		}
	}

	for(int y=0; y<=windowHeight; y++){
		for(int x=0;x<=windowWidth; x++){
			if ((x-(center_x+33.0f))*(x-(center_x+33.0f)) + (y-(center_y-13.0f))*(y-(center_y-13.0f)) <= (30.0f*30.0f)){
				dataArray[4*(x + y * windowWidth)] = color.r;
				dataArray[4*(x + y * windowWidth)+1] = color.g;
				dataArray[4*(x + y * windowWidth)+2] = color.b;
				dataArray[4*(x + y * windowWidth)+3] = 255;
			}
		}
	}

	for(int y=0; y<=windowHeight; y++){
		for(int x=0;x<=windowWidth; x++){
			if ((x-(center_x-33.0f))*(x-(center_x-33.0f)) + (y-(center_y-13.0f))*(y-(center_y-13.0f)) <= (30.0f*30.0f)){
				dataArray[4*(x + y * windowWidth)] = color.r;
				dataArray[4*(x + y * windowWidth)+1] = color.g;
				dataArray[4*(x + y * windowWidth)+2] = color.b;
				dataArray[4*(x + y * windowWidth)+3] = 255;
			}
		}
	}



	for(int y=0; y<=windowHeight; y++){
		for(int x=0;x<=windowWidth; x++){
			if ((x-(center_x+24.0f))*(x-(center_x+24.0f)) + (y-(center_y+27.0f))*(y-(center_y+27.0f)) <= (30.0f*30.0f)){
				dataArray[4*(x + y * windowWidth)] = color.r;
				dataArray[4*(x + y * windowWidth)+1] = color.g;
				dataArray[4*(x + y * windowWidth)+2] = color.b;
				dataArray[4*(x + y * windowWidth)+3] = 255;
			}
		}
	}

	for(int y=0; y<=windowHeight; y++){
		for(int x=0;x<=windowWidth; x++){
			if ((x-(center_x-24.0f))*(x-(center_x-24.0f)) + (y-(center_y+27.0f))*(y-(center_y+27.0f)) <= (30.0f*30.0f)){
				dataArray[4*(x + y * windowWidth)] = color.r;
				dataArray[4*(x + y * windowWidth)+1] = color.g;
				dataArray[4*(x + y * windowWidth)+2] = color.b;
				dataArray[4*(x + y * windowWidth)+3] = 255;
			}
		}
	}

}