/// C�digo por:
/// Felipe Vallejo Molina
/// 
/// felipevm07@gmail.com
/// 2024.01


#include <Kernel.h>

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

		Finalize();
	}

	void Kernel::Finalize()
	{
		for (auto& currentTask : listOfTasks)
		{
			currentTask->Finalize();
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