#pragma once
#include "KGraphic\KGLFW\GraphicMain.h"
#include "KOpenGL\OpenGLMain.h"
namespace Linker {
	class Graphic_OpenGL {
	public:
		static void LINK(Graphic::GLFW::GraphicMain * g, OpenGL::OpenGLMain gl);
	};
}