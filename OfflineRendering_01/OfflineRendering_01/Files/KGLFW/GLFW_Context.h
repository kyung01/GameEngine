#pragma once
#include "GLEW_GLFW.h"
#include "I_GLFW_Calls.h"
#include <list>
namespace EASY_GLFW {
	class GLFW_Context {
	private:
		static GLFW_Context * ME;
		static void HDR_KEYS(GLFWwindow* window, int key, int scancode, int action, int mods);// modify the function as you please 
		static void HDR_CURSOR_POS(GLFWwindow* window, double posX, double posY);// modify the function as you please 

		void construct(int width, int height, char * name);
	protected:
	public:
		GLFWwindow * window;
		std::list<I_Calls::I_Loop*> calls_update;
		std::list<I_Calls::I_Keys*> calls_key;
		std::list<I_Calls::I_CursorPos*> calls_cursorPos;

		bool isPollLoopRunning;

		GLFW_Context();
		GLFW_Context(int width, int height, char * name);
		void runLoop();
		void addCalls(void *);
	};

}