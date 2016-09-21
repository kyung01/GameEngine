#pragma once
#include <memory>
#include "glm\glm.hpp"
#include "KGraphic\Shader.h"
namespace Graphic {
	class Object {
	public:
		enum KType{GEOMETRY_TRIANGLE_2D=0,GEOMETRY_RECT_2D};
		KType type;
		std::shared_ptr<Shader> shader;
		glm::mat4 pos, rotation, scale;
		Object();

	};
}