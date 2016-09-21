#pragma once
#include "World.h"
#include "Object.h"

namespace MyWorld {
	class World;
	class Object;
	class Script {
	public:
		void Update(World world, Object me);
	};
}