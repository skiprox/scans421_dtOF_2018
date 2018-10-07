//
//  Mover.cpp
//
//  Created by Tyler Henry on 10/4/18.
//

#include "Mover.hpp"

Mover::Mover()
{
    pos     = glm::vec2( ofRandom(ofGetWidth()), ofRandom(ofGetHeight()) );
    mass    = ofRandom(1,5);

    vel     = glm::vec2(0,0);
    acc     = glm::vec2(0,0);
}

Mover::Mover(glm::vec2 _pos, float _mass){
    pos     = _pos;
    mass    = _mass;
    
    vel     = glm::vec2(0,0);
    acc     = glm::vec2(0,0);
}

void Mover::applyForce(glm::vec2 force)
{
    // force = mass * acceleration
    // acc = force / mass
    
    acc += force/mass;
}

void Mover::applyDampingForce(float strength)
{
    
    // slows the Mover
    
    float length = glm::length(vel);            // speed / "magnitude" of current velocity
    
    if (length != 0.0){                         // avoid illegal division by 0
        
        glm::vec2 direction = vel / length;     // normalize velocity to make speed 1
        applyForce( -direction * strength );    // scale speed and apply force away from velocity
    }
    
}

glm::vec2 Mover::getForce(glm::vec2 _pos, float _mass)
{
    // calculate a force of attraction on mover
    
    glm::vec2 dir   = pos - _pos;  // the target is the attractor
    float distance  = glm::length(dir);
    
    glm::vec2 force = glm::vec2(0,0);   // default to 0 force
    
    if (distance > 0) {     // avoid division by 0
 
        // we'll model gravity:
        // from http://natureofcode.com/book/chapter-2-forces/#chapter02_section9
        //
        // gravity magnitude = (G * mass1 * mass2) / (distance * distance)
        //
        //      where G = gravitational constant
        
        // we'll "clamp" the distance between 5 and 25
        // to prevent super-massive or super-micro gravity forces
        // ... this is a hack to keep things in equilibrium!
        float distanceMod   = ofClamp(distance, 5., 25.);
        
        float strength      = (G * mass * _mass) / (distanceMod * distanceMod);
    
        glm::vec2 dirNorm   = dir / distance;   // normalized direction
        force   = dirNorm * strength;
    
    }
    return force;
}


void Mover::bounceWindowEdges() {
    
    // keep Mover on screen (bounce off edges)
    
    // if (pos.x < 0) {
    //     pos.x = 0;
    //     vel.x *= -1;
    // }
    
    // if (pos.x > ofGetWidth()) {
    //     pos.x = ofGetWidth();
    //     vel.x *= -1;
    // }
    
    // if (pos.y < 0) {
    //     pos.y = 0;
    //     vel.y *= -1;
    // }
    
    // if (pos.y > ofGetHeight()) {
    //     pos.y = ofGetHeight();
    //     vel.y *= -1;
    // }
}

void Mover::update()
{
    vel += acc;
    pos += vel;
    
    acc *= 0;
}

void Mover::draw()
{
    
    ofPushStyle();
    
    // interpolate between colors!
    ofColor cSlow    = ofColor::fromHex(0xC1D5FF);    // hex format: 0xRRGGBB
    ofColor cFast    = ofColor::fromHex(0xFF4831);
    
    float percent    = ofMap(glm::length(vel), 0., 7., 0., 1., true);    // mix based on speed
    ofColor color   = cSlow.lerp(cFast, percent);    // "lerp" == interpolate
    
    ofSetColor(color);
    
    ofDrawCircle(pos, mass * 2.0);  // base radius on mass
    
    ofPopStyle();
    
}
