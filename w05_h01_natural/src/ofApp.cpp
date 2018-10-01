#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(255);
    ofSetCircleResolution(100);
    previousTime = ofGetElapsedTimef();
	for (int i = 0; i < 3; i++) {
		Leaf leaf;
		glm::vec2 pos;
		pos.x = ofRandom(100, ofGetWidth() - 100);
		pos.y = ofRandom(ofGetHeight() + 100, ofGetHeight() + 200);
		float width = ofRandom(80, 100);
		float height = width * ofRandom(1.1, 1.5);
		leaf.setup(pos, width, height);
		leaves.push_back(leaf);
	}
}

//--------------------------------------------------------------
void ofApp::update(){
	vector<int> toDelete;
	for (int i = 0; i < leaves.size(); i++) {
		if (leaves[i].getCurrentPos().y < -100) {
			leaves.erase(leaves.begin() + i);
		} else {
			leaves[i].update();
		}
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
	pos.y = ofRandom(ofGetHeight() + 100, ofGetHeight() + 200);
	float width = ofRandom(80, 100);
	float height = width * ofRandom(1.1, 1.5);
	leaf.setup(pos, width, height);
	leaves.push_back(leaf);
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	if (previousTime < ofGetElapsedTimef() - 0.2) {
		previousTime = ofGetElapsedTimef();
		Leaf leaf;
		glm::vec2 pos;
		pos.x = x;
		pos.y = ofRandom(ofGetHeight() + 100, ofGetHeight() + 200);
		float width = ofRandom(80, 100);
		float height = width * ofRandom(1.1, 1.5);
		leaf.setup(pos, width, height);
		leaves.push_back(leaf);
	}
}
