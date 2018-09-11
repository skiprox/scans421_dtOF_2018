#pragma once
#include "ofMain.h"

class Square {
	public:
		void setup(float _xPos, float _yPos, float _diam, float _velX, float _velY);
		void update();
		void draw();

		float xPos, yPos, diam, velX, velY;
};