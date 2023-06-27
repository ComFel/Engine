/// Código por:
/// Felipe Vallejo Molina
/// 
/// felipevm07@gmail.com
/// 2023.06

#pragma once

using namespace std;

#include "Scene.hpp"
#include <vector>

namespace engine
{
	class  SceneManager
	{
	private:

		vector<Scene*> scenes;
		vector<size_t> activeScenes;

	public:

		// Singleton to obtein the sceneManager obj from outside this class
		// Static function to ensure its only existance in the execution
		static SceneManager& instance() 
		{
			static SceneManager sceneManager;
			return sceneManager;
		}

		SceneManager();
		SceneManager(Scene * scene);

		void AddScene(Scene* scene);

		Scene* GetScene(size_t number);
		Scene* GetScene(string id);

		void ActiveScene(string id);

		void SetDeactiveScene(size_t number);
		void SetDeactiveScene(string id);

		// here created demo??
		void CreateDemoEngineWindow();
		void DeleteDemoEngineWindow();
		void ResetDemoEngineWindow();
	};
}
