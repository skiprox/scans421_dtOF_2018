#pragma once
#include "ofMain.h"

class Square {
	public:
		void setup(glm::vec2 _pos, float _diam, int _iterator);
		void update();
		void draw();
		glm::vec2 getCenter();

		glm::vec2 pos;
		float diam;
		int iterator;
};
