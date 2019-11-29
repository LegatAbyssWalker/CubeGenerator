#include "PlayingState.h"

//Texture files
static const char* grassTexturePath = "res/images/grass.png"; //Grass texture
static const char* dirtTexturePath  = "res/images/dirt.png";  //Dirt texture

PlayingState::PlayingState(StateMachine& machine, GLWindow& glWindow, bool replace)
	: State{ machine, glWindow, replace } {

	//Camera
	//camera = Camera(glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.f, 1.f, 0.f), -90.f, 0.f, 2.5f, 0.3f);

	//Player information


	//Cube
	cubeVector.resize(10);
	for (GLsizei x = 0; x < cubeVector.size(); x++) {
		cubeVector[x].setTexture(Texture::get(grassTexturePath));
		cubeVector[x].setPosition(glm::vec3(x, 0.f, 0.f));
	}
}

void PlayingState::updateEvents() {
	//Get + Handle user input events
	glfwPollEvents();

	player.updateEvents(glWindow);
}

void PlayingState::update() {
	/*-------------------------------------------------------------------------------------------------------------------*/
	//Delta time
	GLfloat currentFrame = glfwGetTime();
	deltaTime = currentFrame - lastFrame;
	lastFrame = currentFrame;


	/*-------------------------------------------------------------------------------------------------------------------*/
	//Camera updates
	//camera.processKeyboard(glWindow.getKeys(), deltaTime);
	//camera.processMouseMovement(glWindow.getXChange(), glWindow.getYChange());

	/*-------------------------------------------------------------------------------------------------------------------*/
	//Player updates
	player.update(deltaTime);
}

void PlayingState::render() {
	//Clear window
	glClearColor(0.5f, 1.f, 1.f, 1.f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//TODO (TRY TO GET CAMERA FROM PLAYER TO GO TO CUBE)
	for (auto& cube : cubeVector) { cube.render(glWindow, player.camera()); }

	glUseProgram(0);

	glWindow.swapBuffers();
}