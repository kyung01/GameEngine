#include <iostream>
#include "KGLFW\GLFW_Context.h"

#include "PlayerInput.h"
#include "InputCall.h"
#include "GameMain.h"

#include "KGraphic\KGLFW\GraphicMain.h"
#include "KOpenGL\OpenGLMain.h"
#include "Linker\Graphic_OpenGL.h"

void main();
void loop();

class DummyClass :public EASY_GLFW::I_Calls::I_Loop, public Input::I_InputCall {
public:
	void call_loop() {
		loop();
	}
	void call_key(int key, int state) {
		//std::cout << "KEY PRESSED " << key << " " << state << std::endl;
	}
};

Graphic::Scene loadScene00() {
	Graphic::Scene scene;
	scene.cams.push_back(Graphic::Camera());
	Graphic::Object triangle, rect;
	triangle.type = Graphic::Object::KType::GEOMETRY_TRIANGLE_2D;
	rect.type = Graphic::Object::KType::GEOMETRY_RECT_2D;
	scene.objects.push_back(triangle);
	scene.objects.push_back(rect);
	return scene;
}
Input::PlayerInput*			playerInput;
Game::GameMain*				myGameMain;
Graphic::GLFW::GraphicMain*	graphicMain;
OpenGL::OpenGLMain*			glMain;
Graphic::Scene *scene;
void main() {
	EASY_GLFW::GLFW_Context context(500, 500, "KyungHwan Chang");
	playerInput = new Input::PlayerInput();
	myGameMain = new Game::GameMain();
	graphicMain = new Graphic::GLFW::GraphicMain();
	scene = new Graphic::Scene(loadScene00());
	glMain = new OpenGL::OpenGLMain();


	DummyClass _class;

	playerInput->callsKeyboard.push_back(myGameMain);
	playerInput->callsMousePos.push_back(myGameMain);

	context.calls_update.push_back(&_class);
	context.calls_key.push_back(playerInput);
	context.calls_cursorPos.push_back(playerInput);
	playerInput->callsKeyboard.push_back(&_class);

	graphicMain->init(context.window);
	context.runLoop();
	system("pause");
}
void loop() {
	if (playerInput == NULL)return;
	playerInput->update();
	graphicMain->render(*scene);
}