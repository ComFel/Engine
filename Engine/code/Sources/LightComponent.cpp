/// Código por:
/// Felipe Vallejo Molina
/// 
/// felipevm07@gmail.com
/// 2024.01
 
#include <LightComponent.h>
#include <Entity.h>

namespace engine 
{
	LightComponent::LightComponent(Entity* entity, RenderSystem& renderSystem) 
	{
		light.reset(new Light);
		this->myEntity = entity;
		renderSystem.renderNode->add(*myEntity->Get_Entity_ID(), light);
	}

}