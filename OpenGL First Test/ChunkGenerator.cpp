#include "ChunkGenerator.h"

ChunkGenerator::ChunkGenerator(GLint chunkXPos) {
	//Cube generation
	int vecNumber = 0;
	GLuint yAmount = CHUNK_SIZE; //HEIGHT AMPLITUDE AFTERWARDS

	for (GLsizei x = 0; x < CHUNK_SIZE; x++) {
		for (GLsizei z = 0; z < CHUNK_SIZE; z++) {
			for (GLsizei y = 0; y < yAmount; y++) {
				cubeVector.emplace_back(new CubeGenerator());


				/*cubeY = heightGenerator->generateHeight(cubeVector[vecNumber]->getPosition().x,
					cubeVector[vecNumber]->getPosition().z);*/

				if (y < yAmount - 1) { cubeVector[vecNumber]->setTexture(Texture::get(DIRT_TEXTURE_LOCATION)); }
				else { cubeVector[vecNumber]->setTexture(Texture::get(GRASS_TEXTURE_LOCATION)); }

				cubeVector[vecNumber]->setPosition(glm::vec3((GLint)x + (GLint)chunkXPos, (GLint)y, (GLint)z));


				vecNumber++;
			}
		}
	}
}

void ChunkGenerator::update() {

}

void ChunkGenerator::render(GLWindow& glWindow, glm::mat4 viewMatrix) {
	for (auto& cube : cubeVector) {
		cube->render(glWindow, viewMatrix);
	}
}
