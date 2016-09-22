#pragma once
#include "InputEnums.h"

namespace Input {
	class I_InputCall {
	public:
		virtual void call_key(int key, KEY_STATE state) = 0;
	};
	class I_CursorPosCall {
	public:
		virtual void call_cursorPos(double x, double y) = 0;
	};
}