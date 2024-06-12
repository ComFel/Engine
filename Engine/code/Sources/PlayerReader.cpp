/// Código por:
/// Felipe Vallejo Molina
/// 
/// felipevm07@gmail.com
/// 2024.01

#include <PlayerReader.h>
#include <PlayerController.hpp>

namespace engine
{
	
	PlayerReader::PlayerReader(Entity* entity, PlayerController* playerController)
	{
		this->myEntity = entity;
		this->myPlayer = playerController;
		this->dirDown  = 0;
		this->dirUp	   = 0;
	}


	void PlayerReader::Reciver(SDL_Event evento) 
	{
		if (evento.type == SDL_KEYDOWN) 
		{
			switch (evento.key.keysym.sym)
			{
			case SDLK_s:
				dirDown = -1;
				break;

			case SDLK_w:
				dirUp = 1;
				break;

			case SDLK_ESCAPE:
				SDL_Quit();
				break;

			default:
				break;
			}
		}
		else if(evento.type == SDL_KEYUP)
		{
			switch (evento.key.keysym.sym)
			{
			case SDLK_s:
				dirDown = 0;
				break;

			case SDLK_w:
				dirUp = 0;
				break;

			default:
				break;
			}
		}

		myPlayer->Set_Direction(dirUp, dirDown);

	}
}