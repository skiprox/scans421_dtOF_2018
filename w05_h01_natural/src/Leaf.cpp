#include "Leaf.hpp"

//--------------------------------------------------------------
void Leaf::setup(glm::vec2 _pos, float _width, float _height){
	pos = _pos;
	width = _width;
	height = _height;
	vel.x = 0;
	vel.y = ofRandom(-1, -4);
	deg = ofRandom(-10, 10);
	noiseyDeg = ofNoise(ofGetElapsedTimef() + 25);
	color = ofColor(ofRandom(60, 140), 40, ofRandom(180, 240));
	noiseyVel.x = ofNoise(ofGetElapsedTimef());
	noiseyVel.y = ofNoise(ofGetElapsedTimef() + 100);
}

//--------------------------------------------------------------
void Leaf::update(){
	noiseyVel.x = ofNoise(ofGetElapsedTimef()) - 0.5;
	noiseyVel.y = ofNoise(ofGetElapsedTimef() + 100) - 0.5;
	noiseyDeg = ofNoise(ofGetElapsedTimef() + 25) - 0.5;
	deg += noiseyDeg;
	pos.x += 1 * vel.x + noiseyVel.x;
	pos.y += 1 * vel.y + noiseyVel.y;
}

//--------------------------------------------------------------
void Leaf::draw(){
	ofPushMatrix();
	ofSetColor(color);
	ofTranslate(pos);
	ofRotate(deg);
	ofDrawEllipse(0, 0, width, height);
	ofPopMatrix();
}

//--------------------------------------------------------------
glm::vec2 Leaf::getCurrentPos(){
	return pos;
}
