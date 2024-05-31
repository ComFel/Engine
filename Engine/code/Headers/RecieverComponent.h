/// Código por:
/// Felipe Vallejo Molina
/// 
/// felipevm07@gmail.com
/// 2024.01

#pragma once

#include <Component.h>
#include <SDL.h>


namespace engine 
{
	class ReciverComponet : public Component 
	{

	public:
		virtual void Reciver(SDL_Event evento) {};
	};

}
