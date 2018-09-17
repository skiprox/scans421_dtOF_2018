#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	ofBackground(0);
	ofSetCircleResolution(100);

	pos.x = ofRandom(50, ofGetWidth() - 50);
	pos.y = ofGetHeight()/2;

}

//--------------------------------------------------------------
void ofApp::update(){
	glm::vec2 mouse;
	mouse.x = ofGetMouseX();
	mouse.y = ofGetMouseY();

	float pct = 0.05;

	pos = pos * (1 - pct) + mouse * pct;
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(40, 120, 255);
	ofDrawCircle(pos, diam);
	ofSetColor(255);
}

//--------------------------------------------------------------
glm::vec2 ofApp::getCenter(){
	float cx = pos.x + diam * 0.5;
	float cy = pos.y + diam * 0.5;
	return glm::vec2(cx, cy);
}
