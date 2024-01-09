/// Código por:
/// Felipe Vallejo Molina
/// 
/// felipevm07@gmail.com
/// 2024.01

#include <headers/MeshComponent.hpp>
#include <headers/Entity.h>

namespace engine 
{
	MeshComponent::MeshComponent(Entity* entity, const string& path, RenderSystem& renderSystem) 
	{
		this->myEntity = entity;
		myEntity->Add_Component(this);

		AssignModel(path);
		renderSystem.renderNode->add(myEntity->Get_Entity_ID(), model);
	}

	void MeshComponent::AssignModel(const string& path) 
	{
		model.reset(new Model_Obj(path));
	}
}
