#pragma once

#include <DirectXMath.h>
#include <memory>
#include <list>
#include "Mesh.h"
#include "DXCore.h"
#include "SimpleShader.h"
#include "WorldMain.h"
#include "Input\PlayerInput.h"

class KContext
	: public DXCore
{

private:
	World::WorldMain world;


public:
	KContext(HINSTANCE hInstance);
	~KContext();

	// Overridden setup and game loop methods, which
	// will be called automatically
	void Init();
	void OnResize();
	void Update(float deltaTime, float totalTime);
	void Draw(float deltaTime, float totalTime);

	// Overridden mouse input helper methods
	void OnMouseDown(WPARAM buttonState, int x, int y);
	void OnMouseUp(WPARAM buttonState, int x, int y);
	void OnMouseMove(WPARAM buttonState, int x, int y);
	void OnMouseWheel(float wheelDelta, int x, int y);
};

