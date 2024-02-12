/// Código por:
/// Felipe Vallejo Molina
/// 
/// felipevm07@gmail.com
/// 2024.01

#pragma once

#include <System.h>
#include <SDL.h>
#include <vector>
#include <Kernel.h>

using namespace std;

namespace engine
{
	class InputSystem : public System
	{
	protected:
		vector<SDL_Event*> inputRecivers;

	public:

		InputSystem(int priority, Kernel* kernel);

		void Run() override;
		void AddReciver(SDL_Event * reciver);
	};
}
