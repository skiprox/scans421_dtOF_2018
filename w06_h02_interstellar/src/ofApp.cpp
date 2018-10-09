#include "ofApp.h"

// we declare these values as "globals" - they are outside of any class
//--------------------------------------------------------------

const int nMovers		= 10;
const int nAttractors	= 3;
// "const" means the values can never change (they are "hard-coded" here)


//--------------------------------------------------------------
// ofApp class definitions:
//--------------------------------------------------------------
void ofApp::setup(){
	
	ofBackground(0);
	ofSetBackgroundAuto(false);         // don't clear the background each frame
	ofSetFrameRate(60.);                // limit frame rate to 60 frames per second

	// construct Movers and Attractors
	
	// movers
	for (int m=0; m<nMovers; m++)
	{
		movers.push_back(Mover());
	}
	
	// attractors
	glm::vec2 center = glm::vec2( ofGetWidth() *.5, ofGetHeight() * .5 );	// center screen
	
	for (int a=0; a<nAttractors; a++)
	{
		Attractor attractor;
		attractor.pos   = center;
		attractor.pos.x = (center.x + 250.) - (250. * a);
		attractor.pos.y = center.y;
		
		attractors.push_back(attractor);
	}

}

//--------------------------------------------------------------
void ofApp::update(){
	
	// update movers
	for (int a=0; a<nMovers; a++)
	{
		for (int m=0; m<nAttractors; m++)
		{
			// calculate force
			glm::vec2 force = attractors[m].getForce(movers[a]);
            
			// apply force
			movers[a].applyForce(force);
		}
		for (int j = 0; j < nMovers; j++) {
			if (j != a) {
				glm::vec2 force = movers[a].getForce(movers[j].pos, movers[j].mass);
				movers[j].applyForce(force);
			}
		}
		movers[a].update();
	}

}

//--------------------------------------------------------------
void ofApp::draw(){
	
	// manually draw a semi-transparent background
	
	ofSetColor(0, 0, 0, 20); // black with alpha for trails
	ofDrawRectangle(0,0, ofGetWidth(),ofGetHeight());
	
	// draw attractors and movers
	
	for (int a=0; a<nAttractors; a++)
	{
		attractors[a].draw();
	}
	
	for (int m=0; m<nMovers; m++)
	{
		movers[m].draw();
	}

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}
