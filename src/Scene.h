#pragma once
#include <glad\glad.h>
#include <GLFW\glfw3.h>
//#include <ErrorUtil.h>
//#include <DefaultSettings.h>
#include <iostream>
#include <cmath>
#include <vector>

class Scene {
public:
	Scene();
	
	void processInput(GLFWwindow* window);
	void update(GLFWwindow* window);
};