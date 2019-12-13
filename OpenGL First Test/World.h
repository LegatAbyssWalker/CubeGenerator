#ifndef WORLD_H
#define WORLD_H

#include "State.h"
#include "CubeGenerator.h"
#include "GLWindow.h"
#include "Mesh.h"
#include "MoreInfo.h"
#include "FileLocations.h"
#include "Texture.h"
#include "HeightGenerator.h"
#include "ChunkGenerator.h"

#include <iostream>
#include <vector>
#include <memory>

class World {
	public:
		World() = default;
		World(const float HEIGHT_AMPLITUDE);
	
		void update();
		void render(GLWindow& glWindow, glm::mat4 viewMatrix);

		
	private:
		std::unique_ptr<HeightGenerator> heightGenerator = nullptr;
		std::vector<std::unique_ptr<ChunkGenerator>> chunkVector;
};

#endif