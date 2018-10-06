#pragma once

#include "ofMain.h"

class Particle {

	public:
		Particle();
		Particle(glm::vec2 _pos, glm::vec2 _vel, float _mass);
		void addForce(glm::vec2 force);
		void update();
		void draw();
		glm::vec2 getPosition();

		glm::vec2 pos, vel, acc;
		float mass;

		int incrementer = 0;
		
};
