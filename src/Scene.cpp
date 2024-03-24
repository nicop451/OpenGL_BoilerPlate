#include <Scene.h>

Scene::Scene() {

}

void Scene::update(GLFWwindow* window) {
	processInput(window);
}

void Scene::processInput(GLFWwindow* window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}
}


