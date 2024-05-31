/// Código por:
/// Felipe Vallejo Molina
/// 
/// felipevm07@gmail.com
/// 2024.01

#pragma once

#include <RecieverComponent.h>

namespace engine
{
	class PlayerController;

	class PlayerReader : public ReciverComponet 
	{
	protected:
		PlayerController* myPlayer;
		int dirUp;
		int dirDown;

	public:
		
		PlayerReader(Entity* entity, PlayerController* playerController);

		void Reciver(SDL_Event evento) override;

	};
}
