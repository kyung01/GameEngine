#pragma once
#include <list>
#include "KGraphic\Camera.h"
#include "KGraphic\Object.h"
namespace Graphic {
	class Scene {
	public:
		std::list<Graphic::Camera> cams; // for this scene you need to render these cameras
		std::list<Graphic::Object> objects; //things to be rendered on the screen
	};
}