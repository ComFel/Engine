/// Código por:
/// Felipe Vallejo Molina
/// 
/// felipevm07@gmail.com
/// 2024.01

#pragma once

#include <System.h>
#include <vector>
#include <Kernel.h>
#include <UpdateComponent.hpp>
#include <InputSystem.hpp>
#include <Transform.h>

using namespace std;

namespace engine
{
	class UpdateSystem : public System
	{
	protected:
		vector < UpdateComponent* > componentsUpdate;

	public:
		UpdateSystem(int priority, Kernel * kernel);

		void Run() override;

		void AddPlayerComponent(Entity* entity, float speed, InputSystem& inputSystem);
		void AddBallComponent(Entity* entity, float speed, Transform* position);
	};
}
