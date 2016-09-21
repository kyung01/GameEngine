#pragma once
#include "KGraphic\Shader.h"
#include "KOpenGL\Program_Default.h"
namespace Graphic {
	namespace GLFW {
		class Shader :Graphic::Shader{
		public:
			OpenGL::Program_Default program;

			void use(glm::mat4 projection, glm::mat4 view) override;
			void input(std::string id, float* value) override;
			void input(std::string id, int* value) override;
		};
	}
}