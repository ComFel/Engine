/// Código por:
/// Felipe Vallejo Molina
/// 
/// felipevm07@gmail.com
/// 2024.01


#include <CameraComponent.hpp>
#include <Entity.h>

namespace engine
{
	CameraComponent::CameraComponent(Entity* entity, RenderSystem& renderSystem, float fov, float near, float far, float aspectRadio)
	{
		this->myEntity = entity;
		camera.reset(new Camera(fov, near, far, aspectRadio));
		renderSystem.renderNode->add(*myEntity->Get_Entity_ID(), camera);
	}
}