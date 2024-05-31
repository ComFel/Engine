/// Código por:
/// Felipe Vallejo Molina
/// 
/// felipevm07@gmail.com
/// 2024.01

#pragma once

#include <Render_Component.h>
#include <Light.hpp>
#include <RenderSystem.hpp>

using namespace std;
using namespace glt;

namespace engine
{
	class LightComponent : public Render_Component 
	{
	protected:

		shared_ptr < Light > light = nullptr;

	public:

		Node& Get_Node() override 
		{
			return *light;
		}

		LightComponent(Entity* entity, RenderSystem& renderSystem);
	};
}
