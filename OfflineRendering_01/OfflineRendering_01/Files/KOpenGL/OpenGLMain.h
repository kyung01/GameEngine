#pragma once
#include <string>
#include <map>
#include "Program_Default.h"
namespace OpenGL {
	class OpenGLMain {
	public:
		std::map<int, Program_Default> programs;
		void addProgram(int id, const char * path_vert, const char* path_frag);
		
	};
}