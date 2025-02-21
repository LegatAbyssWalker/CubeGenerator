#ifndef HEIGHTGENERATOR_H
#define HEIGHTGENERATOR_H

#include <iostream>
#include <math.h>

#include "State.h"
#include "Random.h"
#include "MoreInfo.h"

class HeightGenerator {
	public:
		HeightGenerator(const float AMPLITUDE = 10);

		float generateHeight(GLint x, GLint z);

	private:
		float getInterpolatedNoise(GLfloat x, GLfloat z);
		float interpolate(GLfloat a, GLfloat b, GLfloat blend);
		float getSmoothNoise(GLint x, GLint z);
		float getNoise(GLint x, GLint z);

		Random<> random;
		int seed;
		int xOffSet = 0;
		int zOffSet = 0; 

		const float AMPLITUDE = 0.f;
		const float ROUGHNESS = 0.3;
		const int OCTAVES = 3;
};

#endif