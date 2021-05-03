#include "ra.h"
#include "Window.h"
#include "Renderer.h"

uint mataLoc;
uint matbLoc;

int renderer::init() {
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	mataLoc = glGetUniformLocation(window::getProgramID(), "trana");
	matbLoc = glGetUniformLocation(window::getProgramID(), "tranb");
	return 0;
}

int renderer::clearScreen() {
	int x, y;
	glfwGetWindowSize(window::getWindow(), &x, &y);
	glViewport(0, 0, x, y);
	//glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	return 0;
}

int renderer::pushToScreen() { //ought to go back into window?
	/* Swap front and back buffers */
	glfwSwapBuffers(window::getWindow());

	/* Poll for and process events */
	glfwPollEvents();
	return 0;
}

void loadFloat(int location, float value) {
	glUniform1f(location, value);
}
void loadVec3(int location, vec3 value) {
	glUniform3f(location, value.x, value.y, value.z);
}

int renderer::draw(Model &model) {
	glBindVertexArray(model.vaoID);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glBindTexture(GL_TEXTURE_2D, model.textureId);

	loadVec3(mataLoc, model.transform.top);
	loadVec3(matbLoc, model.transform.mid);

	glDrawElements(GL_TRIANGLES, sizeof(uint)*model.vertexCount, GL_UNSIGNED_INT, 0);

	glBindTexture(GL_TEXTURE_2D, 0);
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glBindVertexArray(0);
	return 0;
}

