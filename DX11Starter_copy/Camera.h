#pragma once
#include "Object.h"

namespace World {
	class Camera: public Object {
	protected:
	public:
		glm::mat4 projection;
		Camera();
	};
}