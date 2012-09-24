#pragma once
#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"
#include "Resources.h"
#include "Shape.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Diagonal : public Shape{
	public:
		Diagonal();
		void draw();
		void set(uint8_t* dataArray_new, int x1_new, int y1_new, int x2_new, int y2_new, Color8u color_new);

	private:
		static const int windowWidth = 1024;
		static const int windowHeight = 1024;
		int x1, y1, x2, y2;
		Color8u color;
		uint8_t* dataArray;
};