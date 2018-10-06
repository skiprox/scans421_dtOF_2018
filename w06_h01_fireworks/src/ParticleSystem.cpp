//
//  ParticleSystem.cpp
//


#include "ParticleSystem.hpp"

// Use an initializer list
ParticleSystem::ParticleSystem(){

}

// Overload the constructor
ParticleSystem::ParticleSystem(glm::vec2 _pos){
    pos = _pos;
    for (int i = 0; i < 500; i++) {
        glm::vec2 vel;
        float ranValForCircle = ofRandom(0, 6.28);
        float ranValForSpread = ofRandom(0.1, 6);
        vel.x = sin(ranValForCircle) * ranValForSpread;
        vel.y = cos(ranValForCircle) * ranValForSpread;
        float mass = ofRandom(1, 2);
        Particle particle = Particle(pos, vel, mass);
        particles.push_back(particle);
    }
}

void ParticleSystem::updatePosition(glm::vec2 _pos){
    pos = _pos;
}

void ParticleSystem::update(glm::vec2 force){
    for (int i = 0; i < particles.size(); i++) {
        particles[i].addForce(force);
        particles[i].update();
    }
    for (int i = 0; i < particles.size(); i++) {
        if (particles[i].getPosition().y > ofGetHeight() + 100) {
            particles.erase(particles.begin() + i);
        }
    }
    particleIncrementer++;
}

void ParticleSystem::draw(){
    for (int i = 0; i < particles.size(); i++) {
        particles[i].draw();
    }
}
