#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	ofBackground(0);
	ofSetCircleResolution(100);

    for (int i = 0; i < NSQUARES; i++){
        squares[i].setup(glm::vec2(100, ofGetHeight()/NSQUARES * i), 20, i);
    }

}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i = 0; i < NSQUARES; i++){
        squares[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i = 0; i < NSQUARES; i++){
        squares[i].draw();
    }
}
