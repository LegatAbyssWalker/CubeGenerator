#ifndef CHUNKGENERATOR_H
#define CHUNKGENERATOR_H

#include "State.h"
#include "CubeGenerator.h"
#include "GLWindow.h"
#include "HeightGenerator.h"

#include <iostream>
#include <memory>
#include <vector>

class ChunkGenerator {
	public:
		ChunkGenerator(GLint chunkXPos);

		void update();
		void render(GLWindow& glWindow, glm::mat4 viewMatrix);

		GLuint getChunkSize() { return CHUNK_SIZE; }

	private:
		const GLuint CHUNK_SIZE = 16;

		std::vector<std::unique_ptr<CubeGenerator>> cubeVector;

};

#endif