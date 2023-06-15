/// Código por:
/// Felipe Vallejo Molina
/// 
/// felipevm07@gmail.com
/// 2023.06

#pragma once

using namespace std;

#include "..\headers\SceneManager.hpp"


namespace engine
{

	SceneManager::SceneManager() {}
	// Constructor to create a scene and adding it to the pool (array of scenes)
	SceneManager::SceneManager(Scene* scene)
	{
		AddScene(scene);
	}

	// Function to add scenes into the array
	void SceneManager::AddScene(Scene* scene) 
	{
		scenes.push_back(scene);
	}

	Scene* SceneManager::GetScene(size_t number) 
	{ 
		if (number >= scenes.size()) return nullptr; 

		return scenes[number];
	}

	Scene* SceneManager::GetScene(string id) 
	{
		for (size_t i = 0; i < scenes.size(); i++)
		{
			if (scenes[i]->GetSceceName() == id) 
			{
				return scenes[i];
			}
		}

		return nullptr;
	}

	void SceneManager::SetDeactiveScene(size_t number) 
	{
		if (number >= scenes.size()) return;

		scenes.erase(scenes.begin() + number);
	}
	void SceneManager::SetDeactiveScene(string id) 
	{
		for (size_t i = 0; i < scenes.size(); i++)
		{
			if (scenes[i]->GetSceceName() == id)
			{
				SetDeactiveScene(i);
				return;
			}
		}
	}
}