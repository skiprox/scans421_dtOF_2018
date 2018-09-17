#pragma once

#include "ofMain.h"
#include "Square.h"

#define NSQUARES 10

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		Square squares[NSQUARES];
		
};
