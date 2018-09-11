#include "Square.h"

//--------------------------------------------------------------
void Square::setup(float _xPos, float _yPos, float _diam, float _velX, float _velY){
	xPos = _xPos;
	yPos = _yPos;
	diam = _diam;
	velX = _velX;
	velY = _velY;
}

//--------------------------------------------------------------
void Square::update(){
	xPos += 1 * velX;
	yPos += 1 * velY;
	if (xPos < 0 || xPos > ofGetWidth() - diam) {
		velX *= -1;
	}
	if (yPos < 0 || yPos > ofGetHeight() - diam) {
		velY *= -1;
	}
}

//--------------------------------------------------------------
void Square::draw(){
	ofSetColor(120, 255, 0);
	ofDrawRectangle(xPos, yPos, diam, diam);
}
