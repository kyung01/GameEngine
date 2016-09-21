#pragma once
#include "GLEW_GLFW.h"
namespace EASY_GLFW {
	namespace I_Calls {

		class I_Loop {
		public:
			virtual void call_loop() = 0;
		};
		class I_Keys {
		public:
			virtual void call_keys(GLFWwindow* window, int key, int scancode, int action, int mods) = 0;
		};
		class I_CursorPos {
		public:
			virtual void call_cursorPos(GLFWwindow* window, double posX, double posY) = 0;
		};
	}
}