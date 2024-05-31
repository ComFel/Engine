/// Código por:
/// Felipe Vallejo Molina
/// 
/// felipevm07@gmail.com
/// 2024.01

#pragma once

#include <RenderSystem.hpp>
#include <Entity.h>
#include <CameraComponent.hpp>
#include <MeshComponent.hpp>
#include <Light.hpp>
#include <Cube.hpp>
#include <LightComponent.h>

using namespace std;
using namespace glt;

namespace engine
{	
	RenderSystem::RenderSystem(Window* window, int prior, Kernel* kernel) : System(prior)
	{
		this->window = window;
		this->myPriority = prior;

		renderNode.reset(new Render_Node);
		
		//// Se crean los elementos básicos necesarios para dibujar un cubo:
		//shared_ptr< Camera > camera(new Camera(20.f, 1.f, 50.f, 1.f));
		//shared_ptr< Light  > light(new Light);

		//// Se añaden los nodos a la escena:		
		//renderNode->add("camera", camera);
		//renderNode->add("light", light);

		//// Se configuran algunas propiedades de transformación:

		//renderNode->get("camera")->translate(Vector3(0.f, 0.f, 5.f));
		//renderNode->get("light")->translate(Vector3(10.f, 10.f, 10.f));

		
		kernel->Add_Task(this);
	}

	void RenderSystem::Run()
	{
		GLsizei windowHeight = GLsizei(window->Get_Window_Heigth());
		GLsizei windowWidth = GLsizei(window->Get_Window_Width());

		renderNode->get_active_camera()->set_aspect_ratio((float)windowWidth / windowHeight);

		glViewport(0, 0, windowWidth, windowHeight);

		//glClearColor(0.25f, 0.25f, 0.25f, 1.0f);

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

	void RenderSystem::CreateAndAddLightToRender(Entity* entity)
	{
		AddComponentToRender(new LightComponent(entity, *this));
	}
}