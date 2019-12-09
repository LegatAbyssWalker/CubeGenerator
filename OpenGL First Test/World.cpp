#include "World.h"

World::World(GLuint blockAmount) {
	//Cube generation
	cubeVector.resize(blockAmount);
	for (GLsizei x = 0; x < cubeVector.size(); x++) {
		cubeVector[x].setTexture(Texture::get(GRASS_TEXTURE_LOCATION));
		cubeVector[x].setPosition(glm::vec3(x, 0, 0));
	}
}

void World::update() {
	//Collision detection ? 
}

void World::render(GLWindow& glWindow, glm::mat4 viewMatrix) {
	for (auto& cube : cubeVector) {
		cube.render(glWindow, viewMatrix);
	}
}
