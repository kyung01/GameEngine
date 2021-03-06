#include "Program_Default.h"
#include "KUtility\EASY_STD.h"
#include "KUtility\Easy_OpenGL.h"
using namespace OpenGL;
bool Program_Default::is_shader_compiled(GLuint shader_id)
{
	GLint isCompiled;
	glGetShaderiv(shader_id, GL_COMPILE_STATUS, &isCompiled);
	if (isCompiled) return true;
	return false;
}


Program_Default::Program_Default()
{
	id_program = -1;
}
bool Program_Default::init_shader(char* path_vert, char* path_frag)
{
	Easy_STD::File	file_vert = Easy_STD::READ_FILE((char*)path_vert);
	Easy_STD::File  file_frag = Easy_STD::READ_FILE((char*)path_frag);
	
	if (!init_shader(&id_shader_vert, GL_VERTEX_SHADER, file_vert.array.get(), file_vert.array_used_size)) {
		std::cout << "Program_Default::FAILED TO INITIALIZE VERTEX SHADER" << std::endl;
		return false;
	}
	if (!init_shader(&id_shader_frag, GL_FRAGMENT_SHADER, file_frag.array.get(), file_frag.array_used_size)) {
		std::cout << "Program_Default::FAILED TO INITIALIZE FRAGEMNT SHADER" << std::endl;
		return false;
	}
}

bool Program_Default::init_shader(GLuint * shader_id, GLenum shaderType, char * data, int data_size)
{
	auto glChar = Easy_OpenGL::TO_GLCHARR_ARR(data, data_size);
	*shader_id = glCreateShader(shaderType);
	glShaderSource(*shader_id, 1, &glChar.arr, &glChar.size);
	glCompileShader(*shader_id);
	return Easy_OpenGL::check_shader_compilation(*shader_id);
}
void Program_Default::init_shader_locations()
{
	//id_mat_proj = glGetUniformLocation(id_program, NAME_MATRIX_PROJ);
	//id_mat_viewModel = glGetUniformLocation(id_program, NAME_MATRIX_VIEWMODEL);
	//id_pos = glGetAttribLocation(id_program, NAME_POSITION);
	mat_proj		.init(id_program,"mat_proj",true, Easy_GLSL::GLSL_VARIABLE_TYPE::MAT4);
	mat_viewModel	.init(id_program,"mat_viewModel", true, Easy_GLSL::GLSL_VARIABLE_TYPE::MAT4);
	vert_pos		.init(id_program,"vert_pos", false, Easy_GLSL::GLSL_VARIABLE_TYPE::VEC3);
	vert_texture_pos.init(id_program, "vert_texture_pos", false, Easy_GLSL::GLSL_VARIABLE_TYPE::VEC2);
}
bool Program_Default::init(const char * path_vert, const char * path_frag)
{
	if (!init_shader((char*)path_vert, (char*)path_frag)) return false;
	id_program = glCreateProgram();
	glAttachShader(id_program, id_shader_vert);
	glAttachShader(id_program, id_shader_frag);
	glLinkProgram(id_program);
	GLint linked;
	glGetProgramiv(id_program, GL_LINK_STATUS, &linked);
	std::cout << "CHECKING linked status... " << linked << std::endl;
	if (!linked) return false;	
	init_shader_locations();
	return true;
}


void Program_Default::use(float * data_mat_proj, float * data_mat_viewModel)
{
	if (id_program == -1) {
		std::cout << "error Program_Default::use id_program is -1 program is undefined." << std::endl;
		return;
	}
	glUseProgram(id_program);
	this->mat_proj.assign(data_mat_proj);
	this->mat_viewModel.assign(data_mat_viewModel);
	
}

void Program_Default::unUse()
{
	glUseProgram(0);
}
