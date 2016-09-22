#pragma once
#include <list>
#include <map>
#include "glm\glm.hpp"
#include "InputCall.h"
#include "InputEnums.h"
namespace Input {
	class PlayerInput {
	private:
		struct CursorXY{ double x, y; };
		std::list<int> keysPressed, keysHeld, keysReleased;
		std::list<CursorXY> cursorsXY;
		std::map<int, int> dicKeyState;// store keys and their state 
		bool isRunning;
	public:
		std::list<I_InputCall*> callsKeyboard;
		std::list<I_CursorPosCall*> callsMousePos;
		void call_keys(int key, KEY_STATE state);
		void call_cursorPos(double posX, double posY);
		void update();
	};
}