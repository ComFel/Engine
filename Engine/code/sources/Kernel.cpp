/// Código por:
/// Felipe Vallejo Molina
/// 
/// felipevm07@gmail.com
/// 2023.01


#include "..\..\code\headers\Kernel.h"

namespace engine 
{
	Kernel::Kernel() 
	{
		isActive = true;
	}

	void Kernel::Initilize()
	{
		//Kernel uses this keyword -> auto& to declare the type of the iterator of the set
		for (auto& currentTask : listOfTasks)
		{
			currentTask->Initilize();
		}

		Run();
	}

	void Kernel::Run()
	{
		while (isActive)
		{
			for (auto& currentTask : listOfTasks)
			{
				currentTask->Run();
			}
		}

		End();
	}

	void Kernel::End()
	{
		for (auto& currentTask : listOfTasks)
		{
			currentTask->End();
		}
	}

	void Kernel::Set_Active(bool state)
	{
		this->isActive = state;
	}

	// Add a task to the list
	void Kernel::Add_Task(Task* task)
	{
		listOfTasks.insert(task);
	}

}
