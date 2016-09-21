#include "GameMain.h"
using namespace Game;
#include <iostream>
#include "glm\gtx\quaternion.hpp"

GameMain::GameMain() :
	keyEyeMovement({ 
		{ GLFW_KEY_W,glm::vec4(0,0,1,1) },
		{ GLFW_KEY_S,glm::vec4(0,0,-1,1) },
		{ GLFW_KEY_A,glm::vec4(-1,0,0,1) },
		{ GLFW_KEY_D,glm::vec4(1,0,0,1) } })
{
	myState = GameState::CREATED;
	myState = GameState::PLAYING;
	cursorX = -1;
	cursorY = -1;
	
}
GameState GameMain::getState()
{
	return myState;
}

void Game::GameMain::call_key(int key, int state)
{
	if (myState == GameState::PLAYING) {
		if (state == GLFW_PRESS) {
			for each (auto e in keyEyeMovement)
			{
				if (key == e.first) {
					auto move = e.second * eye.rotation;
					std::cout << move.x << " " << move.y << " " << move.z << std::endl;

				}
			}
		}

	}
}

void Game::GameMain::call_cursorPos(double x, double y)
{
	if (cursorX != -1 && cursorY != -1) {

		if (myState == GameState::PLAYING) {
			for (int i = 0; i < 4; i++) {
				std::cout << "[" << eye.rotation[i][0] << " " << eye.rotation[i][1] << " " << eye.rotation[i][2] << " " << eye.rotation[i][3] << std::endl;
			}
			eye.rotation = glm::toMat4(glm::angleAxis<float>(glm::radians(x - cursorX), glm::vec3(0, 1, 0))) * eye.rotation;
			eye.rotation = glm::toMat4(glm::angleAxis<float>(glm::radians(-(y - cursorY)), glm::vec3(1, 0, 0))) * eye.rotation;
		}
	}
	cursorX = x;
	cursorY = y;
}

void Game::GameMain::update()
{
}

float Game::GameMain::getTimeElapsed()
{
	return 0.01f;
}
