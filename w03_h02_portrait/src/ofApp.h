#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		glm::vec2 getCenter();

		glm::vec2 pos;
		float diam = 50;
		
};
