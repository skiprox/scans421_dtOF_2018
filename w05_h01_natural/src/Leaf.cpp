#include "Leaf.hpp"

//--------------------------------------------------------------
void Leaf::setup(glm::vec2 _pos, float _width, float _height){
	pos = _pos;
	width = _width;
	height = _height;
	vel.x = 0;
	vel.y = ofRandom(-1, -4);
	color = ofColor(ofRandom(60, 140), 40, ofRandom(180, 240));
	noisey.x = ofNoise(ofGetElapsedTimef());
	noisey.y = ofNoise(ofGetElapsedTimef() + 100);
}

//--------------------------------------------------------------
void Leaf::update(){
	noisey.x = ofNoise(ofGetElapsedTimef()) - 0.5;
	noisey.y = ofNoise(ofGetElapsedTimef() + 100) - 0.5;
	pos.x += 1 * vel.x + noisey.x;
	pos.y += 1 * vel.y + noisey.y;
}

//--------------------------------------------------------------
void Leaf::draw(){
	ofSetColor(0);
	ofSetColor(color);
	ofDrawEllipse(pos, width, height);
	ofSetColor(255);
}

//--------------------------------------------------------------
glm::vec2 Leaf::getCurrentPos(){
	return pos;
}
