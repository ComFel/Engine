/// Código por:
/// Felipe Vallejo Molina
/// 
/// felipevm07@gmail.com
/// 2024.01

#pragma once

#include "..\headers\RenderSystem.hpp"
#include "..\headers\Entity.h"
#include "..\headers\CameraComponent.hpp"
#include "..\headers\MeshComponent.hpp"

using namespace std;
using namespace glt;

namespace engine
{	
	RenderSystem::RenderSystem(Window* window, int prior, Kernel* kernel) : System(prior)
	{
		this->window = window;
		this->myPriority = prior;

		renderNode.reset(new Render_Node);
		kernel->Add_Task(this);
	}

	void RenderSystem::Run()
	{
		GLsizei windowHeight = GLsizei(window->Get_Window_Heigth());
		GLsizei windowWidth = GLsizei(window->Get_Window_Width());

		renderNode->get_active_camera()->set_aspect_ratio((float)windowWidth / windowHeight);

		glViewport(0, 0, windowWidth, windowHeight);

		// Render components in camera
		for (auto& component : renderComponents)
		{
			if (component && component->Get_Entity()->Get_Entity_Status())
			{
				glm::mat4 transformMatrix = component->Get_Entity()->Get_Transform()->Get_Matrix();
				component->Get_Node().set_transformation(transformMatrix);
			}
		}

		window->Clear_Window(); // Prepare Window for next frame to render
		renderNode->render();
		window->Swap_Buffers(); // Swap the front and back buffers of the windows
	}
	
	void RenderSystem::AddComponentToRender(Render_Component* component) 
	{
		renderComponents.push_back(component);
	}

	void RenderSystem::CreateAndAddMeshToRender(Entity* entity, string path)
	{
		AddComponentToRender(new MeshComponent(entity, path, *this));
	}

	void RenderSystem::CreateAndAddCameraToRender(Entity* entity)
	{
		AddComponentToRender(new CameraComponent(entity, *this, 20.f, 1.f, 50.f, 1.f)); // ToDo: Magic Numbers need to move them
	}
}