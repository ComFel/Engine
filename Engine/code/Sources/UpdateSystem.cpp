/// Código por:
/// Felipe Vallejo Molina
/// 
/// felipevm07@gmail.com
/// 2024.01

#include <UpdateSystem.hpp>
#include <PlayerController.hpp>

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
		componentsUpdate.push_back(new PlayerController(entity, speed, inputSystem));
	}

	void UpdateSystem::AddBallComponent(Entity* entity, float speed, Transform* position) 
	{
		// Add Ball update status to the update to be managed from the sceneManager
	}
}
