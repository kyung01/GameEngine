#pragma once
#include "imgui_impl_dx11.h"
/**
	Using imgi dx11 implementation, and leaving the DXCore and window initialization work needed to others.
**/
namespace KUI {

	class UIContext {
	public:
		UIContext(void* hwnd, ID3D11Device* device, ID3D11DeviceContext* device_context);

	};
}