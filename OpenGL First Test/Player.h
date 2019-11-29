#ifndef PLAYER_H
#define PLAYER_H

#include "State.h"
#include "Camera.h"
#include "GLWindow.h"
#include "MoreInfo.h"

#include <iostream>

class Player {
	public:
		Player();

		void updateEvents(GLWindow& glWindow);
		void update(GLfloat deltaTime);

		//TODO `get camera class` function


	private:
		GLfloat deltaTime;

		GLuint screenWidth = SCREEN_WIDTH;
		GLuint screenHeight = SCREEN_HEIGHT;

		Camera camera;
		GLfloat lastX = screenWidth / 2.f;
		GLfloat lastY = screenHeight / 2.f;
		bool firstMouse = true;
};

#endif