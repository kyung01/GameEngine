#include "OpenGLMain.h"
using namespace OpenGL;
void OpenGLMain::addProgram(int id, const char * path_vert, const char* path_frag) {
	Program_Default e;
	e.init(path_vert, path_frag);
}