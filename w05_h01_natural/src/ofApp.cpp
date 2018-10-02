#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0);
    ofSetCircleResolution(100);
    previousTime = ofGetElapsedTimef();
    glEnable(GL_DEPTH_TEST);
    ofEnableSmoothing();
    ofEnableDepthTest();
    ofSetSphereResolution(100);
    light.setDiffuseColor( ofFloatColor(.85, .85, .55) );
    light.setSpecularColor( ofFloatColor(1.f, 1.f, 1.f));
    light.setPosition(ofGetWidth()/2, ofGetHeight() + 800, -500);
	for (int i = 0; i < 3; i++) {
		Leaf leaf;
		glm::vec3 pos;
		pos.x = ofRandom(100, ofGetWidth() - 100);
		pos.y = ofRandom(ofGetHeight() + 200, ofGetHeight() + 400);
		pos.z = ofRandom(-200, 200);
		float width = ofRandom(80, 100);
		float height = width * ofRandom(1.1, 1.5);
		leaf.setup(pos, width, height);
		leaves.push_back(leaf);
	}
}

//--------------------------------------------------------------
void ofApp::update(){
	light.setPosition(ofGetWidth()/2, ofGetHeight(), 500);
	vector<int> toDelete;
	for (int i = 0; i < leaves.size(); i++) {
		if (leaves[i].getCurrentPos().y < -400) {
			leaves.erase(leaves.begin() + i);
		} else {
			leaves[i].update();
		}
	}
    ofDisableSeparateSpecularLight();
}

//--------------------------------------------------------------
void ofApp::draw(){
	cam.begin();
	ofTranslate(-ofGetWidth()/2, -ofGetHeight()/2);
	light.enable();
    ofEnableLighting();
	for (int i = 0; i < leaves.size(); i++) {
		leaves[i].draw();
	}
	light.disable();
    ofDisableLighting();
    cam.end();
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	Leaf leaf;
	glm::vec3 pos;
	pos.x = x;
	pos.y = y;
	pos.z = ofRandom(-200, 200);
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
		glm::vec3 pos;
		pos.x = x;
		pos.y = ofRandom(ofGetHeight() + 200, ofGetHeight() + 400);
		pos.z = ofRandom(-200, 200);
		float width = ofRandom(80, 100);
		float height = width * ofRandom(1.1, 1.5);
		leaf.setup(pos, width, height);
		leaves.push_back(leaf);
	}
}
