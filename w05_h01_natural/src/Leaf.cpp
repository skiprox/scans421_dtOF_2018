#include "Leaf.hpp"

//--------------------------------------------------------------
void Leaf::setup(glm::vec3 _pos, float _width, float _height){
	pos = _pos;
	width = _width;
	height = _height;
	vel.x = 0;
	vel.y = ofRandom(-1, -4);
	deg = ofRandom(-10, 10);
	noiseyDeg = ofNoise(ofGetElapsedTimef() + 25);
	float ranColorVal = ofRandom(1);
	if (ranColorVal < 0.33) {
		color = ofColor(ofRandom(60, 140), 40, ofRandom(180, 240));
	} else if (ranColorVal < 0.66) {
		color = ofColor(40, ofRandom(180, 240), ofRandom(60, 140));
	} else {
		color = ofColor(ofRandom(180, 240), 40, ofRandom(60, 140));
	}
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
	ofSpherePrimitive sphere;
	ofSetColor(color);
	ofTranslate(pos);
	// ofRotate(deg);
	ofRotateYDeg(deg);
	sphere.setRadius(width);
	sphere.setPosition(0, 0, pos.z);
	sphere.draw();
	//ofDrawEllipse(0, 0, width, height);
	ofPopMatrix();
}

//--------------------------------------------------------------
glm::vec2 Leaf::getCurrentPos(){
	glm::vec2 newPos;
	newPos.x = pos.x;
	newPos.y = pos.y;
	return newPos;
}
