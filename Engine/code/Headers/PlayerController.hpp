/// Código por:
/// Felipe Vallejo Molina
/// 
/// felipevm07@gmail.com
/// 2023.06

#pragma once

#include <UpdateComponent.hpp>
#include <InputSystem.hpp>
#include <PlayerReader.h>

namespace engine
{
	class PlayerController : public UpdateComponent
	{
	private:
		int dirUp;
		int dirDown;
		float speed;

	public:
		PlayerController(Entity* entity, float speed, InputSystem& inputSystem);

		void  Set_Speed(float speed);
		float Get_Speed();

		void Update() override;

		void Set_Direction(int dirUp, int dirDown);
	};
}
