#include "FrameCounter.h"
#include "../render/Window.h"
#include "../render/Texture.h"
#include "../render/Vao.h"
#include "../render/ShaderGen.h"
#include "../render/Renderer.h"

FrameCounter::FrameCounter() {
	out = getCell();
	for (int i = 0; i < 10; i++) {
		std::stringstream ss;
		ss << "res/textures/num/" << i << ".png";
		textures[i] = loadTexture(ss.str(), GL_NEAREST);
	}
}

int FrameCounter::update(timesys::system_clock::duration deltaTime) {
	sumTime += deltaTime;
	frames++;
	return 0;
}

int FrameCounter::fixedUpdate() {
	int ms = (int)timesys::duration_cast<timesys::milliseconds>(sumTime).count();
	if (ms != 0) {
		fps = (frames * 1000) / ms;
	}

	frames = 0;
	sumTime = timesys::system_clock::duration();

	return 0;
}

int FrameCounter::getRenderArr(std::queue<Model>& arr) {
	int num = fps;
	std::vector<int> digits;
	while (num > 0) {
		digits.push_back(num % 10);
		num /= 10;
	}

	float width = 30.0f / window::getWindowSize().x; //30 pixels wide
	float height = 30.0f / window::getWindowSize().y; //30 pixels tall
	float gap = width / 2;

	for (int i = 0; i < digits.size(); i++) {
		out.transform.top = { width, 0.0f, (width + gap) * i - 1.0f + gap};
		out.transform.mid = { 0.0f, height, 1.0f - height};

		out.textureId = textures[digits[digits.size() - (1 + i)]];

		arr.push(out);
	}

	return 0;
}

Model FrameCounter::getCell() {
	Model out = createVAO();
	std::vector<vec2> v = { {-1.0f, 1.0f},
							{ 1.0f, 1.0f},
							{ 1.0f,-1.0f},
							{-1.0f,-1.0f} }; //100% size
	std::vector<vec2> t = { {0.0f,0.0f},{1.0f,0.0f},{1.0f,1.0f},{0.0f,1.0f} };
	loadVertexData(out, v);
	loadTextureCoordinates(out, t);
	uint prog = GenerateProgram("res/shaders/core.vert", "res/shaders/core.frag");
	out.programId = prog;
	return out;
}

int FrameCounter::cleanup() {
	return 0;
}
