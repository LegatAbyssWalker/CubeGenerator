#include "Player.h"

Player::Player() {
	
	//Camera
	camera = Camera(glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.f, 1.f, 0.f), -90.f, 0.f, 2.5f, 0.3f);

}

void Player::updateEvents(GLWindow& glWindow) {
	camera.processKeyboard(glWindow.getKeys(), deltaTime);
	camera.processMouseMovement(glWindow.getXChange(), glWindow.getYChange());
}

void Player::update(GLfloat deltaTime) {
	this->deltaTime = deltaTime;
}
