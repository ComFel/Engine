/// Código por:
/// Felipe Vallejo Molina
/// 
/// felipevm07@gmail.com
/// 2024.01

#include <InputSystem.hpp>

namespace engine
{
	InputSystem::InputSystem(int priority, Kernel* kernel) : System (priority)
	{
		this->myPriority = priority;
		kernel->Add_Task(this);
	}

	void InputSystem::Run()
	{
		SDL_Event inputEvent;

		// While there is an input still in the poll
		while (SDL_PollEvent(&inputEvent) > 0)
		{
			for (auto reciever : inputRecivers)
			{
				// ToDo : Make class for reciver?
				
				// if (inputEvent.type == SDL_KEYDOWN)
				// {
				//     // Handle keydown event
				// }
				// else if (inputEvent.type == SDL_MOUSEBUTTONDOWN)
				// {
				//     // Handle mouse button down event
				// }

				// SDL_Quit al cerrar ventana
			}
		}
	}

	void InputSystem::AddReciver(SDL_Event* reciver)
	{
		inputRecivers.push_back(reciver);
	}
}
