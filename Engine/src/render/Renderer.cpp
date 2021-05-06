#include "ra.h"
#include "Window.h"
#include "Renderer.h"

uint objectMat;
uint cameraMat;
uint currentProgram;

int renderer::init() {
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	setProgram(window::getProgramID());
	objectMat = glGetUniformLocation(window::getProgramID(), "trans");
	cameraMat = glGetUniformLocation(window::getProgramID(), "camera");
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

int renderer::setProgram(uint progId) {
	currentProgram = progId;
	glUseProgram(progId);
	return 0;
}

int renderer::draw(Model &model) {
	if (model.programId != currentProgram)
		setProgram(model.programId);
	glBindVertexArray(model.vaoID);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glBindTexture(GL_TEXTURE_2D, model.textureId);

	glUniformMatrix3fv(objectMat, 1, GL_TRUE, &model.transform.top.x);

	glDrawElements(GL_TRIANGLES, sizeof(uint)*model.vertexCount, GL_UNSIGNED_INT, 0);

	glBindTexture(GL_TEXTURE_2D, 0);
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glBindVertexArray(0);
	return 0;
}

int renderer::loadGlobalTransform(uint progID, TransMatrix mat) {
	setProgram(progID);
	glUniformMatrix3fv(cameraMat, 1, GL_TRUE, &mat.top.x);
	return 0;
}

