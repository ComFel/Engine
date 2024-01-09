/// Código por:
/// Felipe Vallejo Molina
/// 
/// felipevm07@gmail.com
/// 2024.01

#pragma once

#include <headers/Scene.hpp>

using namespace std;

namespace engine
{
	Scene::Scene(const string& id, Window& window)
	{
		this->id = id;
		this->kernel = new Kernel();

		SceneManager::instance().AddScene(this);

		renderSystem.reset(new RenderSystem(&window, 0, kernel));
		inputSystem.reset(new InputSystem  (		 1, kernel));
		updateSystem.reset(new UpdateSystem(		 2, kernel));
	}

	void Scene::Initialize() 
	{ 
		kernel->Initilize(); 
	}

	void Scene::Update(float time) {}

	void Scene::Render() 
	{ 
		renderSystem->Run(); 
	}

	void Scene::AddEntittyToScene(Entity* entity)
	{
		// Check the map if the entity already exists
		if(entitysMap.find(entity->Get_Entity_ID()) != entitysMap.end())
		{
			// Create a id for the new entity
			unsigned iterator = 0;
			string temp = entity->Get_Entity_ID();

			while(entitysMap.find(temp) != entitysMap.end())
			{
				++iterator;
				temp = entity->Get_Entity_ID() + to_string(iterator);
			}

			entity->Set_Entity_ID(temp);
		}

		entitysMap.insert(pair<string, Entity*>(entity->Get_Entity_ID(), entity));
	}

	Entity* Scene::GetEntityInScene(const string* id) { return this->entitysMap[*id]; }
}
