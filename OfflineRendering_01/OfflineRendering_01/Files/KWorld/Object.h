#pragma once
#include "glm\glm.hpp"
#include "World.h"
#include "Script.h"
#include <list>
namespace MyWorld {
	class World;
	class Script;
	class Object {
	protected:
	public:
		std::list<Script> scripts;
		glm::mat4 position, scale, rotation;

		Object();
		void Update(World world);
		
	};
}