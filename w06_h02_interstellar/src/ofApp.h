#pragma once

#include "ofMain.h"
#include "Mover.hpp"
#include "Attractor.hpp"

class ofApp : public ofBaseApp{

public:
	void setup();
	void update();
	void draw();

	void mouseReleased(int x, int y, int button);
	
	vector<Attractor> attractors;
	vector<Mover> movers;
		
};
