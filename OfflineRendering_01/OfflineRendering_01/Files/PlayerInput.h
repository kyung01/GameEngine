#pragma once
#include "glm\glm.hpp"
#include "KGLFW\I_GLFW_Calls.h"
#include "InputCall.h"
#include <list>
#include <map>
namespace Input {
	class PlayerInput :public EASY_GLFW::I_Calls::I_Keys, public EASY_GLFW::I_Calls::I_CursorPos{
	private:
		struct CursorXY{ double x, y; };
		std::list<int> keysPressed, keysHeld, keysReleased;
		std::list<CursorXY> cursorsXY;
		std::map<int, int> dicKeyState;// store keys and their state 
		bool isRunning;
	public:
		std::list<I_InputCall*> callsKeyboard;
		std::list<I_CursorPosCall*> callsMousePos;
		void call_keys(GLFWwindow* window, int key, int scancode, int action, int mods);
		void call_cursorPos(GLFWwindow* window, double posX, double posY);
		void update();
	};
}