#include "PlayerInput.h"
#include <iostream>
using namespace Input;
void PlayerInput::call_keys(int key, KEY_STATE state)
{
	dicKeyState[key] = state;
	if (state == KEY_STATE_PRESSED) keysPressed.push_back(key);
}

void PlayerInput::call_cursorPos(double posX, double posY)
{
	cursorsXY.push_back(CursorXY{ posX,posY });
	std::cout << " " << posX << " " << posY << std::endl;
}

void PlayerInput::update()
{
	if (!cursorsXY.empty()) {
		for (auto xy = cursorsXY.begin(); xy != cursorsXY.end(); xy++) {
			for (auto it = callsMousePos.begin(); it != callsMousePos.end(); it++) {
				(**it).call_cursorPos(xy->x, xy->y);
			}
		}
		cursorsXY.clear();
	}
	for (auto it = keysPressed.begin(); it != keysPressed.end(); it++) {
		for (auto itCall = callsKeyboard.begin(); itCall != callsKeyboard.end(); itCall++) {
			(**itCall).call_key(*it, KEY_STATE_PRESSED);
		}
	}
	for (auto it = keysHeld.begin(); it != keysHeld.end(); it++) {
		for (auto itCall = callsKeyboard.begin(); itCall != callsKeyboard.end(); itCall++) {
			(**itCall).call_key(*it, KEY_STATE_REPEAT);
		}
	}
	for (auto it = keysReleased.begin(); it != keysReleased.end(); it++) {
		for (auto itCall = callsKeyboard.begin(); itCall != callsKeyboard.end(); itCall++) {
			(**itCall).call_key(*it, KEY_STATE_RELEASED);
		}
	}
	keysReleased.clear();
	for (auto it = keysHeld.begin(); it != keysHeld.end();) {
		if (dicKeyState[*it] == KEY_STATE_RELEASED) {
			keysReleased.push_back(*it);
			it = keysHeld.erase(it);
		}
		else it++;
	}
	if (!keysPressed.empty()){
		keysHeld.insert(keysHeld.end(), keysPressed.begin(), keysPressed.end());
		keysPressed.clear();
	}
}
