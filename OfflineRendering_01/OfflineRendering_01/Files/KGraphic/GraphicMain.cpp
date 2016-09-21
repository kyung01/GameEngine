#include "KGraphic\GraphicMain.h"
#include "GL\glew.h"
void Graphic::GraphicMain::processObject(Object obj) {
	if (obj.shader != NULL) {

		Graphic::Shader *shader = shaders[obj.shader->type];
		shader->use(this->matProjection, this->matView);
	}
	//models[obj.type]->draw();
	glColor3f(1, 0, 1);
	glBegin(GL_TRIANGLES);
	glVertex3f(0, 0, 0);
	glVertex3f(1, 0, 0);
	glVertex3f(0, 1, 0);
	glEnd();
}


void Graphic::GraphicMain::rendering(Scene scene)
{
	for (auto cam = scene.cams.begin(); cam != scene.cams.end(); cam++) {
		processCamera(*cam);
		for (auto it = scene.objects.begin(); it != scene.objects.end(); it++) {
			//processShader(it->shader);
			processObject(*it);
			//draw the object
		}
	}
	
}

void Graphic::GraphicMain::render(Graphic::Scene scene)
{
	beginRendering();
	rendering(scene);
	endRendering();
}