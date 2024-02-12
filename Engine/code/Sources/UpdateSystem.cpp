/// Código por:
/// Felipe Vallejo Molina
/// 
/// felipevm07@gmail.com
/// 2024.01

#include "..\headers\UpdateSystem.hpp"


namespace engine
{
	UpdateSystem::UpdateSystem(int priority, Kernel * kernel) : System(priority)
	{
		this->myPriority = priority;
		kernel->Add_Task(this);
	}

	void UpdateSystem::Run()
	{
		for (auto update : componentsUpdate) 
		{
			update->Update();
		}
	}

	void UpdateSystem::AddPlayerComponent(Entity* entity, float speed, InputSystem& inputSystem) 
	{
		// Add players update status to the update to be managed from the sceneManager
	}

	void UpdateSystem::AddBallComponent(Entity* entity, float speed, Transform* position) 
	{
		// Add Ball update status to the update to be managed from the sceneManager
	}
}
