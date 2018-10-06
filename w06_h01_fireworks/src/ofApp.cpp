#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	// ofBackground(0);
	ofSetBackgroundAuto(false);
	ofSetCircleResolution(100);
	gravity = glm::vec2(0, 0.1);
	ParticleSystem ps = ParticleSystem(glm::vec2(ofGetWidth()*0.5, ofGetHeight()*0.5));
	particleSystems.push_back(ps);
}

//--------------------------------------------------------------
void ofApp::update(){
	for (int i = 0; i < particleSystems.size(); i++) {
		particleSystems[i].update(gravity);
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(0, 0, 0, 40);
	ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
	for (int i = 0; i < particleSystems.size(); i++) {
		particleSystems[i].draw();
	}
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	ParticleSystem ps = ParticleSystem(glm::vec2(x, y));
	particleSystems.push_back(ps);
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	// particleSystem.updatePosition(glm::vec2(x, y));
}
