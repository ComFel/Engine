/// Código por:
/// Felipe Vallejo Molina
/// 
/// felipevm07@gmail.com
/// 2023.06

#pragma once

#include "System.h"
#include "Window.hpp"
#include "Kernel.h"
#include "Render_Node.hpp"
#include "Render_Component.h"
#include <vector>

using namespace std;
using namespace glt;

namespace engine 
{
	// Class that renders all needed elements within it
	class RenderSystem : public System 
	{
	private:
		Window* window;

		vector<Render_Component*> renderComponents;

		void AddComponentToRender(Render_Component* component);

	public:
		RenderSystem(Window* window, int prior, Kernel* kernel);
		
		unique_ptr<Render_Node> renderNode;

		void Run() override;

		void CreateAndAddMeshToRender(Entity* entity, string path);
		void CreateAndAddCameraToRender(Entity* entity);
	};
}
