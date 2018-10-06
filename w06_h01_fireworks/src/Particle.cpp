//
//  Particle.cpp
//


#include "Particle.hpp"

// Use an initializer list
Particle::Particle()
: pos(0, 0),
  vel(0, 0),
  acc(0, 0)
{
    // pos = glm::vec2(0, 0);
    // vel = glm::vec2(0, 0);
    // acc = glm::vec2(0, 0);
}

// Overload the constructor
Particle::Particle(glm::vec2 _pos, glm::vec2 _vel, float _mass){
    pos = _pos;
    vel = _vel;
    mass = _mass;
}

void Particle::addForce(glm::vec2 force){
    acc += force / mass;
}

void Particle::update(){
    vel += acc;
    pos += vel;
    // set acceleration back to zero
    acc *= 0;
}

void Particle::draw(){
    ofPushStyle();
    ofSetColor(ofColor(254, ofRandom(180, 255), 10, ofClamp(255-incrementer, 0, 255)));
    incrementer++;
    ofDrawCircle(pos, 3);
    ofPopStyle();
}

glm::vec2 Particle::getPosition(){
    return pos;
}
