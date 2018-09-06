#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetBackgroundAuto(false);
	ofBackground(20);
	// Squares
	for (int i = 0; i < NSQUARES; i++){
	    groupOfSquares[i].setup(ofRandom(0, ofGetWidth() - 20), ofRandom(0, ofGetHeight() - 20), 20, ofRandom(5, 20), ofRandom(5, 20));
	}
}

//--------------------------------------------------------------
void ofApp::update(){
	// increment the global counter
	counter++;
	// Squares
	for (int i = 0; i < NSQUARES; i++){
	    groupOfSquares[i].update();
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(20, 20, 20, 20);
	ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
	// Squares
	for (int i = 0; i < NSQUARES; i++){
	    groupOfSquares[i].draw();
	}
	// Large squares
	if (counter % 50 == 0) {
		ofBackground(20);
		for (int i = 0; i < NLARGESQUARES; i++) {
			ofSetColor(ofRandom(150, 255), 0, 120);
	        float width = ofRandom(50, 150);
	        float height = ofRandom(50, 150);
	        float xOffset = ofRandom(-640, 640);
	        float yOffset = ofRandom(-640, 640);
	        ofDrawRectangle(ofGetWidth()/2+xOffset, ofGetHeight()/2+yOffset, width, height);
		}
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	if (key == 'f') {
		ofToggleFullscreen();
	}
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	// velX *= 2;
	// velY *= 2;
	cout << "we clicked" << endl;
	ofBackground(20);
	for (int i = 0; i < NLARGESQUARES; i++) {
		ofSetColor(ofRandom(150, 255), 0, 120);
        float width = ofRandom(50, 150);
        float height = ofRandom(50, 150);
        float xOffset = ofRandom(-340, 340);
        float yOffset = ofRandom(-340, 340);
        ofDrawRectangle(ofGetMouseX()+xOffset, ofGetMouseY()+yOffset, width, height);
	}
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
