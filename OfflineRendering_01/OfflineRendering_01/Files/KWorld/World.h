#pragma once
#include "Object.h"
#include <list>

namespace MyWorld {
	class Object;
	class Script;

	class World {
	protected:
		std::list<Object> objects;
	public:
		void update();
	};
}