#include "../global/Shorts.h"
#include "Window.h"
#include "ShaderGen.h"
#include "Renderer.h"

GLFWwindow* windowPane;
uint programID;

bool window::isRunning() {
	return !glfwWindowShouldClose(windowPane);
}

int window::init(const char windowTitle[]) {
	/* Initialize the library */
	if (!glfwInit()) return -2;

	windowPane = glfwCreateWindow(1280, 960, windowTitle, NULL, NULL);
	if (!windowPane) {
		glfwTerminate();
		return -2;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(windowPane);

	if (glewInit() != GLEW_OK) return -3;

	debugPrint(glGetString(GL_VERSION));

	return 0;
}

int window::myinit() {
	programID = GenerateProgram("res/shaders/core.vert", "res/shaders/core.frag");

	glUseProgram(programID);
	renderer::init();

	return 0;
}

rect window::getWindowSize(){
	rect out;
	glfwGetWindowSize(windowPane, &out.x, &out.y);
	return out;
}

GLFWwindow* window::getWindow(){
	return windowPane;
}

uint window::getProgramID(){ //Should rename to get defaultProgId
	return programID;
}

int window::close() {
	glfwTerminate();
	return 0;
}