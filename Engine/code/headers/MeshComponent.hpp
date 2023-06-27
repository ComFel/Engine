/// Código por:
/// Felipe Vallejo Molina
/// 
/// felipevm07@gmail.com
/// 2023.06

#pragma once

#include "Render_Component.h"
#include "RenderSystem.hpp"
#include "Model_Obj.hpp"
#include "Model.hpp"

using namespace std;
using namespace glt;

namespace engine 
{	
	class MeshComponent : public Render_Component
	{
	private:
		shared_ptr<Model> model = nullptr;

	public:
		MeshComponent(Entity* entity, const string& path, RenderSystem& renderSystem);
		~MeshComponent() = default;

		void AssignModel(const string& path);
		Node& Get_Node() override { return *model; }
	};
}