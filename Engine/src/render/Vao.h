#pragma once

#include "../global/Shorts.h"
#include <vector>
#include "Model.h"

Model createVAO();
int deleteVAO(Model &model);

void loadVertexData(Model& model, std::vector<vec2> data);
void loadTextureCoordinates(Model& model, std::vector<vec2> data);

//Semi private below
uint loadVec2Buffer(Model& model, int attribNum, std::vector<vec2> data);
uint loadVec3Buffer(Model& model, int attribNum, std::vector<vec2> data);
uint loadIndicesBuffer(std::vector<uint> indices);

std::vector<uint> triangulate(uint vertexCount);

