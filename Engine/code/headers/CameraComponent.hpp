/// Código por:
/// Felipe Vallejo Molina
/// 
/// felipevm07@gmail.com
/// 2023.06


#pragma once

#include "Render_Component.h"
#include "Camera.hpp"
#include "RenderSystem.hpp"


using namespace std;
using namespace glt;

namespace engine
{
	class CameraComponent : public Render_Component
	{
	protected:
		shared_ptr<Camera> camera = nullptr;

	public:
		// Constructor
		CameraComponent(Entity* entity, RenderSystem& render, float fov, float near, float far, float aspectRadio);

		Node& Get_Node() override
		{
			return *camera;
		}

	};
}
