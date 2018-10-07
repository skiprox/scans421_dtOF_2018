//
//  Mover.hpp
//
//  Created by Tyler Henry on 10/4/18.
//

#pragma once
#include "ofMain.h"

class Mover {
    
public:
    
    // constructors
    Mover();
    Mover(glm::vec2 _pos, float _mass);
    
    // functions
    void applyForce(glm::vec2 force);
    void applyDampingForce(float strength);

    glm::vec2 getForce(glm::vec2 _pos, float _mass);

    void bounceWindowEdges();   // keep Mover on screen
    
    void update();
    void draw();
    
    // variables
    glm::vec2 pos, vel, acc;
    float mass;
    const float G = .4;     // gravitational constant
    
};
