#include "ra.h"
#include "Vao.h"
#include "Renderer.h"
#include "Window.h"

Model createVAO() {
	uint vaoId;
	glGenVertexArrays(1, &vaoId);
	glBindVertexArray(vaoId);

	Model out = Model(vaoId);
	out.programId = window::getProgramID();

	glBindVertexArray(0);
	return out;
}

int deleteVAO(Model &model) {
	glDeleteVertexArrays(1, &model.vaoID);
	/*
	for (auto const i : model.vbos) {
		glDeleteBuffers(1, &i);
	}
	*/
	return 0;
}

void loadVertexData(Model& model, std::vector<vec2> data) {
	glBindVertexArray(model.vaoID);
	model.vertexCount = (uint) data.size();
	model.vertexVBO = loadVec2Buffer(model, 0, data);

	std::vector<uint> indices = triangulate((uint)data.size());
	model.indicesVBO = loadIndicesBuffer(indices);
	glBindVertexArray(0);
}

void loadTextureCoordinates(Model& model, std::vector<vec2> data) {
	glBindVertexArray(model.vaoID);
	model.textureCoordsVBO = loadVec2Buffer(model, 1, data);
	glBindVertexArray(0);
}






//Semi private below
uint loadVec2Buffer(Model& model, int attribNum, std::vector<vec2> data) {
	uint vboId;
	glGenBuffers(1, &vboId); //Create vbo
	glBindBuffer(GL_ARRAY_BUFFER, vboId); //Bind vbo

	glBufferData(GL_ARRAY_BUFFER, sizeof(vec2)*data.size(), data.data(), GL_STATIC_DRAW); //Put data in vbo
	glVertexAttribPointer(attribNum, 2, GL_FLOAT, false, 0, 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0); //Unbind vbo
	return vboId;
}

uint loadVec3Buffer(Model& model, int attribNum, std::vector<vec3> data) {
	uint vboId;
	glGenBuffers(1, &vboId); //Create vbo
	glBindBuffer(GL_ARRAY_BUFFER, vboId); //Bind vbo

	glBufferData(GL_ARRAY_BUFFER, sizeof(vec3)*data.size(), data.data(), GL_STATIC_DRAW); //Put data in vbo
	glVertexAttribPointer(attribNum, 3, GL_FLOAT, false, 0, 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0); //Unbind vbo
	return vboId;
}

uint loadIndicesBuffer(std::vector<uint> indices) {
	uint vboId;
	glGenBuffers(1, &vboId);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vboId);

	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(uint)*indices.size(), indices.data(), GL_STATIC_DRAW);
	return vboId;
}

std::vector<uint> triangulate(uint vertexCount) {
	//TODO: Find a better algo

	std::vector<uint> out;
	for (uint i = 0; i < vertexCount - 2; i++) {
		out.push_back(0);
		out.push_back(i + 1);
		out.push_back(i + 2);
	}

	return out;
}