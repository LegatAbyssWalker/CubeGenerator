#ifndef CUBEGENERATOR_H
#define CUBEGENERATOR_H

#include "State.h"
#include "Mesh.h"
#include "Program.h"
#include "Texture.h"
#include "Camera.h"
#include "GLWindow.h"

#include <iostream>
#include <vector>

class CubeGenerator {
	public:
		CubeGenerator();

		void setTexture(std::shared_ptr<Texture> texture);
		void setPosition(glm::vec3 position = glm::vec3(0.f, 0.f, 0.f));
		void setScale(glm::vec3 scale = glm::vec3(0.5f, 0.5f, 0.5f));

		void update(GLWindow& glWindow, Camera& camera);
		void render(GLWindow& glWindow);

		glm::vec3 getPosition();

	private:
		Mesh mesh;
		std::shared_ptr<Program> program;
		std::shared_ptr<Texture> texture;

		glm::mat4 model;
		glm::mat4 view;
		glm::mat4 projection;

		glm::vec3 position;
		glm::vec3 scaleValue;

		std::vector<GLuint> vertices;
};

#endif