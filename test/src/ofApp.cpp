#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetVerticalSync(true);
	ofBackground(20);
}

//--------------------------------------------------------------
void ofApp::update(){
	pointLight.setPosition((ofGetWidth()*.5)+ cos(ofGetElapsedTimef()*.5)*(ofGetWidth()*.3), ofGetHeight()/2, 500);
    pointLight2.setPosition((ofGetWidth()*.5)+ cos(ofGetElapsedTimef()*.15)*(ofGetWidth()*.3),
                            ofGetHeight()*.5 + sin(ofGetElapsedTimef()*.7)*(ofGetHeight()), -300);

    pointLight3.setPosition(
                            cos(ofGetElapsedTimef()*1.5) * ofGetWidth()*.5,
                            sin(ofGetElapsedTimef()*1.5f) * ofGetWidth()*.5,
                            cos(ofGetElapsedTimef()*.2) * ofGetWidth()
    );
}

//--------------------------------------------------------------
void ofApp::draw(){
	cam.setGlobalPosition({ 0,0,cam.getImagePlaneDistance(ofGetCurrentViewport()) });
	cam.begin();
	ofEnableDepthTest();
	ofEnableLighting();
	pointLight.enable();
	pointLight2.enable();
	pointLight3.enable();
	//  Draw a green sphere
    ofSetColor(0, 255, 0);
    ofFill();
    ofDrawSphere(xPos, yPos, radius);
    ofDisableLighting();
    ofDisableDepthTest();
	cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	// radius = (x + y) * 0.25;
	xPos = x - ofGetWidth()/2;
	yPos = - y + ofGetHeight()/2;
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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
