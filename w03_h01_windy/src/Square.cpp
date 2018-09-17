#include "Square.h"

//--------------------------------------------------------------
void Square::setup(glm::vec2 _pos, float _diam, int _iterator){
	pos.x = _pos.x;
	pos.y = _pos.y;
	diam = _diam;
	iterator = _iterator;
}

//--------------------------------------------------------------
void Square::update(){
	float tempX = 0;
    // Get a position between 0 and 1 based on the elapsed time, linearly using sine
	tempX = ofMap(sin(ofGetElapsedTimef() + iterator), -1, 1, 0, 1);
    // Do ease in out quad function based on this number
    if (tempX < 0.5) {
        tempX = 2 * tempX * tempX;
    } else {
        tempX = -1 + (4 - 2 * tempX) * tempX;
    }
    // map that number back to a position in the canvas
    pos.x = ofMap(tempX, 0, 1, 0, ofGetWidth());
}

//--------------------------------------------------------------
void Square::draw(){
	ofSetColor(40, 120, 255);
	ofDrawCircle(pos, diam);
	ofSetColor(255);
}

//--------------------------------------------------------------
glm::vec2 Square::getCenter(){
	float cx = pos.x + diam * 0.5;
	float cy = pos.y + diam * 0.5;
	return glm::vec2(cx, cy);
}
