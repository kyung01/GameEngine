#pragma once
#include <list>
#include "Object.h"
#include "Camera.h"
namespace World {
	class WorldMain {
	public:
		Camera cam;
		std::list<Object> objs;
		WorldMain();
		void update(float timeElapsed);
	};
}