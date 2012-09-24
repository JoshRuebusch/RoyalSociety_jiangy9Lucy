#pragma once
#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"
#include "Resources.h"
#include "Shape.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class VerticalLine : public Shape{
	public:
		VerticalLine();
		void draw();
		void set(uint8_t* dataArray_new, int y1_new, int y2_new, int x_new, Color8u color_new);

	private:
		static const int windowWidth = 1024;
		static const int windowHeight = 1024;
		int y1,y2,x;
		Color8u color;
		uint8_t* dataArray;
};