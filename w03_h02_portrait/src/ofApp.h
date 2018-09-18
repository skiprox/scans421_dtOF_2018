#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		
		// Eyes
		glm::vec2 eyeInnerLeft, eyeInnerRight, eyeOuterLeft, eyeOuterRight;
		glm::vec2 eyeInnerLeftMove, eyeInnerRightMove;
		float eyeInnerDiam, eyeOuterDiam;

		// Mouth
		glm::vec2 mouth;
		glm::vec2 mouthMove;
		float mouthWidth, mouthHeight;

		// Nose
		glm::vec2 nose;
		float noseWidth, noseHeight, noseColorMove;
};
