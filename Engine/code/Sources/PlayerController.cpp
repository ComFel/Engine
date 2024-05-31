

#include <PlayerController.hpp>
#include <Transform.h>
#include <Entity.h>


namespace engine
{
	PlayerController::PlayerController(Entity* entity, float speed, InputSystem& system)
	{
		this->myEntity = entity;
		this->speed = speed;
		dirUp = 0;
		dirDown = 0;

		system.AddReciver(new PlayerReader(entity, this));

	}


	void PlayerController::Set_Speed(float speed)
	{
		this->speed = speed;
	}

	float PlayerController::Get_Speed()
	{
		return this->speed;
	}

	void PlayerController::Set_Direction(int dirUp, int dirDown)
	{

		this->dirUp = dirUp;
		this->dirDown = dirDown;
	}


	void PlayerController::Update()
	{
		//Si no se esta moviendo saltamos este update
		if (dirUp == 0 && dirDown == 0) return;

		vec3 direction = normalize(vec3(0.0f, dirUp - dirDown, 0.0f));
		direction *= speed;

		this->Get_Entity()->Get_Transform()->Translate(direction);

		//Limites de la pantalla 
		//Esto se podria haber hecho con un systemCollider pero teniendo en cuenta lo que se pide en la entrega no creo que este justificado
		glm::vec3 position = this->Get_Entity()->Get_Transform()->Get_Position();

		if (position.y < -5.5f) position.y = -5.5f;
		else if (position.y > 5.5f) position.y = 5.5f;

		this->Get_Entity()->Get_Transform()->Set_Position(position);

	}
}