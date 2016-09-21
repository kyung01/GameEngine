#pragma once
#include <string>
namespace OpenGL {
	class Shader {
	public:
		virtual void use() = 0;
		virtual void input(std::string id, float* value) = 0;
		virtual void input(std::string id, int* value) = 0;
	};
}