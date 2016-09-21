#include "KGraphic\KGLFW\GraphicMain.h"
#include "glm\gtc\matrix_transform.hpp"
#include "glm\gtc\type_ptr.hpp"

void Graphic::GLFW::GraphicMain::processCamera(Graphic::Camera cam)
{
	int width, height;
	glfwGetWindowSize(window, &width, &height);
	if (cam.viewType == Graphic::Camera::CAMERA_TYPE::PERSPECTIVE)
		matProejction = glm::perspective<float>(cam.fov, width / (float)height, 0, 100);
	else
		matProejction = glm::ortho<float>(0, width, 0, height);
	vec4 camPosition = cam.position * vec4(0, 0, 0, 1);
	vec4 camLookAt = cam.rotation * vec4(0, 0, 1, 1);
	matView = glm::lookAt<float>(glm::vec3(camPosition),glm::vec3(camLookAt), glm::vec3(0,1,0));
}
void Graphic::GLFW::GraphicMain::beginRendering()
{
	int w, h;
	float ratio;
	glfwGetFramebufferSize(window, &w, &h);
	ratio = w / (float)h;
	glViewport(0, 0, w, h);
	glClearColor(1, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Graphic::GLFW::GraphicMain::endRendering()
{
}


void Graphic::GLFW::GraphicMain::getScreenWidth(int & w, int & h)
{
	glfwGetFramebufferSize(window, &w, &h);
}

void Graphic::GLFW::GraphicMain::init(GLFWwindow * window)
{
	this->window = window;
}
