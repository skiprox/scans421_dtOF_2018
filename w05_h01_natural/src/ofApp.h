#pragma once

#include "ofMain.h"
#include "Leaf.hpp"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void mouseReleased(int x, int y, int button);
		void mouseMoved(int x, int y );

		vector<Leaf> leaves;
		float previousTime;
		
};
