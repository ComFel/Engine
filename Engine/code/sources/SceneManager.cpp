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

	void SceneManager::ActiveScene(string id) 
	{
		for (size_t i = 0; i < scenes.size(); i++)
		{
			if (scenes[i]->GetSceceName() == id) 
			{
				scenes[i]->Initialize();
				activeScenes.push_back(i);
			}
		}
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

	void SceneManager::CreateDemoEngineWindow()
	{
		Window* window = new Window("DemoEngine_1", 1280, 720, false);
		Scene* scene   = new Scene("Intro", *window);

		string path = "../../assets/sphere.obj";

		string playLeft  = "LeftBar";
		string playRight = "RightBar";
		string playBall  = "Ball";

		Entity* camera		= new Entity(scene);
		Entity* playerLeft  = new Entity(scene, playLeft);
		Entity* playerRight = new Entity(scene, playRight);
		Entity* ball		= new Entity(scene, playBall);
		

		GetScene("Intro")->renderSystem->CreateAndAddMeshToRender(ball, path);
		
		GetScene("Intro")->renderSystem->CreateAndAddCameraToRender(camera);	

		//input System with player (update)
		playerLeft ->Get_Transform()->Set_Position(Vector3(0,0,0));
		playerRight->Get_Transform()->Set_Position(Vector3(0,0,0));

		ball->Get_Transform()->Set_Position(Vector3(0, 0, 0));	


		GetScene("Intro")->updateSystem->AddPlayerComponent(playerLeft , 0.1f, *GetScene("Intro")->inputSystem);
		GetScene("Intro")->updateSystem->AddPlayerComponent(playerRight, 0.1f, *GetScene("Intro")->inputSystem);

		GetScene("Intro")->updateSystem->AddBallComponent(ball, 0.3f, ball->Get_Transform());

		// Initialize kernel
		ActiveScene("Intro");
	}

	void SceneManager::DeleteDemoEngineWindow() 
	{

	}

	void SceneManager::ResetDemoEngineWindow() 
	{

	}
}