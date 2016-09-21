#pragma once
#include <map>
#include "KGLFW\GLEW_GLFW.h"
#include "KGraphic\GraphicMain.h"
#include "KOpenGL\Program_Default.h"
namespace Graphic {
	namespace GLFW {
		class GraphicMain : public Graphic::GraphicMain {
		private:
			GLFWwindow* window;
			mat4 matProejction, matView;
		protected:
			void processCamera(Camera cam) override;
			void beginRendering() override;
			void endRendering() override;
			void getScreenWidth(int &w, int &h) override;
		public:
			void init(GLFWwindow* window);
			
		};
	}
}