#pragma once
#include "glm\glm.hpp"
namespace Game {
	/*	GameEye is not necessarily player but simply the eye in which game has inside it.
		It is not camera either because this class does not contain any information on how to render things*/
	class GameEye {
	public:
		glm::mat4 position, rotation;
		glm::vec4 normal;

	};
}