#ifndef WORLD_H
#define WORLD_H

#include "State.h"
#include "CubeGenerator.h"
#include "GLWindow.h"
#include "Mesh.h"
#include "MoreInfo.h"
#include "FileLocations.h"
#include "Texture.h"

#include <iostream>
#include <vector>

class World {
	public:
		World() = default;
		World(GLuint blockAmount);
	
		void update();
		void render(GLWindow& glWindow, glm::mat4 viewMatrix);


	private:
		std::vector<CubeGenerator> cubeVector;
};

#endif