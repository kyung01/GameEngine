#include "GLFW_Context.h"
#include <string>
#include <iostream>
EASY_GLFW::GLFW_Context *EASY_GLFW::GLFW_Context::ME = NULL;
void EASY_GLFW::GLFW_Context::HDR_KEYS(GLFWwindow * window, int key, int scancode, int action, int mods)
{
	for (auto it = ME->calls_key.begin(); it != ME->calls_key.end(); it++) {
		(**it).call_keys(window, key, scancode, action, mods);
	}
}
void EASY_GLFW::GLFW_Context::HDR_CURSOR_POS(GLFWwindow * window, double posX, double posY)
{
	for (auto it = ME->calls_cursorPos.begin(); it != ME->calls_cursorPos.end(); it++) {
		(**it).call_cursorPos(window, posX,posY);
	}
}
void EASY_GLFW::GLFW_Context::construct(int width, int height, char * name)
{
	ME = this;
	glfwInit();
	window = glfwCreateWindow(width, height, name, NULL, NULL);
	glfwMakeContextCurrent(window);
	glfwSetKeyCallback(window, HDR_KEYS);
	glfwSetCursorPosCallback(window, HDR_CURSOR_POS);
	glewInit(); // calling this before above code will result in error
	//do {
	//	glfwPollEvents();
	//} while (true);
	glfwSetCursorPos(window, 0, 0);
}

EASY_GLFW::GLFW_Context::GLFW_Context()
{
	construct(512, 512, "Title_Undefined");
}

EASY_GLFW::GLFW_Context::GLFW_Context(int width, int height, char * name)
{
	construct(width, height, name);
}

void EASY_GLFW::GLFW_Context::runLoop()
{
	isPollLoopRunning = true;
	while (isPollLoopRunning) {
		for (auto it = calls_update.begin(); it != calls_update.end(); it++) {
			(**it).call_loop();
		}
		//if (call_update != NULL)call_update->call_pollLoop();//call the function
		glfwPollEvents();
		glfwSwapBuffers(this->window);
	}
}
