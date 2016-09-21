#pragma once
#include <map>
#include "InputCall.h"
#include "GameEye.h"
#include "KGLFW\GLEW_GLFW.h"
namespace Game {
	enum GameState { CREATED, PLAYING, PAUSED, ENDING };
	class GameMain : public Input::I_InputCall , public Input::I_CursorPosCall{
	protected:
		GameState myState;
		GameEye eye;
		std::map<int, glm::vec4> keyEyeMovement;
		double cursorX, cursorY;
	public:
		GameMain();
		GameState getState();
		void call_key(int key, int state);
		void call_cursorPos(double x, double y);
		void update();
		float getTimeElapsed();
	};
}