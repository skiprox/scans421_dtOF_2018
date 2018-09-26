#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(255);
    ofSetCircleResolution(100);
	for (int i = 0; i < 3; i++) {
		Leaf leaf;
		glm::vec2 pos;
		pos.x = ofRandom(100, ofGetWidth() - 100);
		pos.y = ofRandom(20, ofGetHeight()/2);
		float width = ofRandom(80, 100);
		float height = ofRandom(80, 100);
		leaf.setup(pos, width, height);
		leaves.push_back(leaf);
	}
}

//--------------------------------------------------------------
void ofApp::update(){
	for (int i = 0; i < leaves.size(); i++) {
		leaves[i].update();
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	for (int i = 0; i < leaves.size(); i++) {
		leaves[i].draw();
	}
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	Leaf leaf;
	glm::vec2 pos;
	pos.x = x;
	pos.y = y;
	float width = ofRandom(80, 100);
	float height = ofRandom(80, 100);
	leaf.setup(pos, width, height);
	leaves.push_back(leaf);
}
