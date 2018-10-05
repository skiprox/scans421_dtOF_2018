#pragma once

#include "ofMain.h"
#include "Particle.hpp"

class ParticleSystem {

	public:
		ParticleSystem();
		ParticleSystem(glm::vec2 _pos);
		void updatePosition(glm::vec2 _pos);
		void update(glm::vec2 _force);
		void draw();

		glm::vec2 pos, force;

		int particleIncrementer = 0;

		vector<Particle> particles;
		
};
