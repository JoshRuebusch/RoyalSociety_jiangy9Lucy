#pragma once
#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"
#include "Resources.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Shape{
	public:
		virtual void draw() = 0;
		//method: setPosition() for movement;

	private:
		static const int windowWidth = 1024;
		static const int windowHeight = 1024;
};