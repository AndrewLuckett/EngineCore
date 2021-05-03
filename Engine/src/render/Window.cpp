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
	string vesh = ParseFile("res/shaders/light.vert");
	string frsh = ParseFile("res/shaders/light.frag");

	programID = glCreateProgram();

	uint vs = CompileShader(GL_VERTEX_SHADER, vesh);
	uint fs = CompileShader(GL_FRAGMENT_SHADER, frsh);

	glAttachShader(programID, vs);
	glAttachShader(programID, fs);

	glLinkProgram(programID);

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

uint window::getProgramID(){
	return programID;
}

int window::close() {
	glfwTerminate();
	return 0;
}