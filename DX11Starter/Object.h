#pragma once
#include "glm\glm.hpp"
/*
*/
namespace World {
	class Object {
	protected:
	public:
		glm::vec3 pos, rotation, scale;
		Object(); //Object(Material *mat)? I do not like Object taking something not necessary to build Object as aprt of constructor argument 
		void Update(float timeElapsed);
	};
}