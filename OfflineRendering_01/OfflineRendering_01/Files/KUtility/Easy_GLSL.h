#pragma once
#include "KGLFW\GLEW_GLFW.h"
class Easy_GLSL {
public:
	static GLuint INIT_SHADER(char * data, int data_size, GLenum shaderType);
	enum GLSL_VARIABLE_TYPE { MAT4, VEC2, VEC3, VEC4 };

};