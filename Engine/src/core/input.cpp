#include "input.h"
#include "../render/Window.h"

GLFWwindow* win = NULL;

vec2 getCursorLocation(){
	checkWindow();
	double x, y;
	glfwGetCursorPos(win, &x, &y);
	rect windowSize = window::getWindowSize();

	x -= windowSize.x / 2.0f;
	y = windowSize.y / 2.0f - y;
	return {(float) x, (float) y };
}

bool isKeyDown(int keynum){
	checkWindow();
	int state = glfwGetKey(win, keynum);
	if (state == GLFW_PRESS) {
		return true;
	}
	return false;
}

void checkWindow(){
	if (win == NULL) {
		win = window::getWindow();
	}
}
