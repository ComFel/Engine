/// Código por:
/// Felipe Vallejo Molina
/// 
/// felipevm07@gmail.com
/// 2024.01

#pragma once

using namespace std;

#include <SceneManager.hpp>

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
				activeScenes.push_back(i);
				scenes[i]->Initialize();
				scenes[i]->Run();
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

	// Pasar a scene manager a DemoEngine en main.cpp
	void SceneManager::CreateDemoEngineWindow()
	{		
		Window* window = new Window("DemoEngine_1", 1280, 720, false);
		Scene* scene   = new Scene("Intro", *window);

		glClearColor(0.25f, 0.25f, 0.25f, 1.0f);

		string path = "../../assets/sphere.obj";

		string playLeft  = "LeftBar";
		string playRight = "RightBar";
		string playBall  = "Ball";

		Entity* camera		= new Entity(scene);
		Entity* light		= new Entity(scene);
		Entity* playerLeft  = new Entity(scene, playLeft);
		Entity* playerRight = new Entity(scene, playRight);
		Entity* ball		= new Entity(scene, playBall);
		

		/// Creacion Meshes jugables
		GetScene("Intro")->renderSystem->CreateAndAddMeshToRender(playerLeft, path);
		GetScene("Intro")->renderSystem->CreateAndAddMeshToRender(ball, path);		

		/// Adicion del player a la entidad
		GetScene("Intro")->updateSystem->AddPlayerComponent(playerLeft , 0.1f, *GetScene(0)->inputSystem);

		//Movimiento entidades pos inicial
		playerLeft ->Get_Transform()->Translate(Vector3(0,0,-10.f));
		ball->Get_Transform()->Translate(Vector3(0, 0, -10.f));
		

		GetScene("Intro")->updateSystem->AddBallComponent(ball, 0.3f, ball->Get_Transform());

		/// Adicion de la camara y luz en escena
		GetScene("Intro")->renderSystem->CreateAndAddCameraToRender(camera);
		GetScene("Intro")->renderSystem->CreateAndAddLightToRender(light);
		light->Get_Transform()->Translate(Vector3(10.f, 10.f, 10.f));

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