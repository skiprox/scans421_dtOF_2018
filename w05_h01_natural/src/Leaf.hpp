#pragma once
#include "ofMain.h"

class Leaf {
	public:
		void setup(glm::vec2 _pos, float _width, float _height);
		void update();
		void draw();
		glm::vec2 getCurrentPos();

		glm::vec2 pos, vel, noisey;
		float width, height;
		ofColor color;
};
