/// Código por:
/// Felipe Vallejo Molina
/// 
/// felipevm07@gmail.com
/// 2023.01


#pragma once

#include <headers/Task.h>

namespace engine
{
	// Class represents a system, inherits from task that need to be executed in the main loop
	// Represents a interface to manage resources for the system (engine) which uses the priority from tasks to be executed in the told main loop
	class System : public Task
	{
	public:

		// Constructor that sets the priority of the task, used to order its execution
		explicit System(int priority) : Task(myPriority) {}

		virtual void Initilize() = 0;
		virtual void Run() = 0;
		virtual void End() = 0;

		// Destructor that is call from the derived classes
		virtual ~System() = default;

	};
}
