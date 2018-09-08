#include "SquarePattern.h"

//--------------------------------------------------------------
void SquarePattern::draw(){
	for (int i = 0; i < NLARGESQUARES; i++) {
		ofSetColor(ofRandom(150, 255), 0, 120);
        float width = ofRandom(50, 150);
        float height = ofRandom(50, 150);
        float xOffset = ofRandom(-640, 640);
        float yOffset = ofRandom(-640, 640);
        ofDrawRectangle(ofGetWidth()/2+xOffset, ofGetHeight()/2+yOffset, width, height);
	}
}