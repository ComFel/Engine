/// Código por:
/// Felipe Vallejo Molina
/// 
/// felipevm07@gmail.com
/// 2024.01

#pragma once

#include <iostream>
#include <map>
#include "Entity.h"
#include "Kernel.h"
#include "RenderSystem.hpp"
#include "SceneManager.hpp"
#include "InputSystem.hpp"
#include "UpdateSystem.hpp"


using namespace std;

namespace engine
{
	class Window;

	class Scene
	{
	private:

		string id;
		map<string, Entity*> entitysMap;

		Kernel* kernel;

	public:
		// Constructor of class scene, need a ref to the window and a id to know what scene is
		Scene(const string& id, Window& window);

		void Initialize();
		void Update(float time);
		void Render();

		string GetSceceName() { return id; }

		void AddEntittyToScene(Entity* entity);
		Entity* GetEntityInScene(const string* id);

		//RenderSystem, ... systems
		unique_ptr <RenderSystem> renderSystem;
		unique_ptr <InputSystem > inputSystem;
		unique_ptr <UpdateSystem> updateSystem;
	};
}