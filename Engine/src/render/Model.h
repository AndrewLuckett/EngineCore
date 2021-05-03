#pragma once
#include "../global/Shorts.h"
#include "../global/Matrix.h"
#include <vector>



typedef struct Model {
	uint vaoID;
	Default(uint, vertexCount);
	Default(uint, vertexVBO);
	Default(uint, indicesVBO);
	Default(uint, textureCoordsVBO);

	TransMatrix transform;

	Default(uint, textureId);

	Model() : Model(0){}
	Model(uint vi) {
		vaoID = vi;
	}

} Model;

/*
* VAO
* Element buffer : IndicesArray
* 0 : VertexArray
* 1 : TextureCoordinateArray
*/