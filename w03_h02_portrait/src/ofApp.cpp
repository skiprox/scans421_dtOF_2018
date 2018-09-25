#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	ofBackground(253, 246, 201);
	ofSetCircleResolution(100);

	// Eyes
	eyeOuterLeft.x = ofGetWidth()/2 - 200;
	eyeOuterLeft.y = 200;
	eyeInnerLeft.x = ofGetWidth()/2 - 200;
	eyeInnerLeft.y = 200;
	eyeOuterRight.x = ofGetWidth()/2 + 200;
	eyeOuterRight.y = 200;
	eyeInnerRight.x = ofGetWidth()/2 + 200;
	eyeInnerRight.y = 200;
	eyeOuterDiam = 100;
	eyeInnerDiam = 50;

	// Mouth
	mouth.x = ofGetWidth()/2;
	mouth.y = ofGetHeight()/2 + 200;
	mouthMove.x = mouth.x;
	mouthMove.y = mouth.y;
	mouthWidth = 400;
	mouthHeight = 200;

	// Nose
	nose.x = ofGetWidth()/2;
	nose.y = ofGetHeight()/2;
	noseWidth = 100;
	noseHeight = 100;

}

//--------------------------------------------------------------
void ofApp::update(){
	// Eyes
	eyeInnerLeftMove.x = eyeInnerLeft.x + eyeInnerDiam/2 * cos(ofGetElapsedTimef() * 8);
	eyeInnerLeftMove.y = eyeInnerLeft.y + eyeInnerDiam/2 * sin(ofGetElapsedTimef() * 8);
	eyeInnerRightMove.x = eyeInnerRight.x + eyeInnerDiam/2 * sin(ofGetElapsedTimef() * 8);
	eyeInnerRightMove.y = eyeInnerRight.y + eyeInnerDiam/2 * cos(ofGetElapsedTimef() * 8);
	// Mouth
	glm::vec2 mouse;
	mouse.x = ofMap(ofGetMouseX(), 0, ofGetWidth(), mouth.x - 100, mouth.x + 100);
	mouse.y = ofMap(ofGetMouseY(), 0, ofGetHeight(), mouth.y - 100, mouth.y + 100);
	float pct = 0.05;
	mouthMove = mouthMove * (1 - pct) + mouse * pct;
	// Nose
	noseColorMove = ofMap(sin(ofGetElapsedTimef() * 8), -1, 1, 180, 255);
}

//--------------------------------------------------------------
void ofApp::draw(){
	// Eyes
	ofSetColor(240, 240, 80);
	ofDrawCircle(eyeOuterLeft, eyeOuterDiam);
	ofDrawCircle(eyeOuterRight, eyeOuterDiam);
	ofSetColor(40, 120, 255);
	ofDrawCircle(eyeInnerLeftMove, eyeInnerDiam);
	ofDrawCircle(eyeInnerRightMove, eyeInnerDiam);
	// Mouth
	ofSetColor(240, 80, 140);
	ofDrawEllipse(mouthMove, mouthWidth, mouthHeight);
	// Nose
	ofSetColor(noseColorMove, 61, 67);
	ofDrawTriangle(nose.x - noseWidth/2, nose.y + noseHeight/2, nose.x, nose.y - noseHeight/2, nose.x + noseWidth/2, nose.y + noseHeight/2);
	ofSetColor(255);
}
