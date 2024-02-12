/// Código por:
/// Felipe Vallejo Molina
/// 
/// felipevm07@gmail.com
/// 2024.01


#pragma once

#include <Task.h>
#include <set>
#include <memory>

namespace engine 
{
	//Class responsible for managing and executing a set of tasks.
	class Kernel 
	{
	private:
		
		//Check if the kernel is active or not
		bool isActive = true;

	public:

		// Constructor
		Kernel();

		// Setup or initialization
		virtual void Initilize();

		// Perform the main logic of the kernel and execute the tasks.
		virtual void Run();

		// For when we shut down the kernel
		virtual void Finalize();

		// Set state of the kernel
		void Set_Active(bool state);

		// Add task to the kernel
		void Add_Task(Task* task);

		//with Std lib we create a list of pointers to all tasks created so the kernel can see the "myPriority" of tasks store into themselfes
		//std::set<std::unique_ptr<Task>, Task::compare_Task_Priorities> listOfTasks;		
		std::set<Task*, Task::compare_Task_Priorities> listOfTasks;
	};

}
