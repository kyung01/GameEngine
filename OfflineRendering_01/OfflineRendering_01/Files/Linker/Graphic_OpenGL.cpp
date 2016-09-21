#include "Graphic_OpenGL.h"
#include "KOpenGL\KVertexArrayObject.h"
using namespace Linker;
void Graphic_OpenGL::LINK(Graphic::GLFW::GraphicMain * g, OpenGL::OpenGLMain gl) {
	std::string path_shader_default = { "Shader/default_vert.txt", "Shader/default_frag.txt" };
	std::string path_shader_deferred = { "Shader/shader_deferred_vert.txt", "Shader/shader_deferred_frag.txt" };
	gl.addProgram(Graphic::Shader::KType::DEFAULT, (const char*)path_shader_default[0], (const char*)path_shader_default[1]);
	gl.addProgram(Graphic::Shader::KType::DEFERRED, (const char*)path_shader_default[0], (const char*)path_shader_default[1]);
	OpenGL::KVertexArrayObject geometry_2d_triangle;
	//Graphic::Shader shader;
	//geometry_2d_triangle.init()
}