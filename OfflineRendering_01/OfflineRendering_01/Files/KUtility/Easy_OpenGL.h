#pragma once
#include <iostream>
#include "KGLFW\GLEW_GLFW.h"
class Easy_OpenGL {
public:
	struct GlCharArr {
		GLchar* arr;
		GLint size;
	};
	static bool check_shader_compilation(GLuint shader_id);
	static GlCharArr TO_GLCHARR_ARR(char * arr, int size);
};