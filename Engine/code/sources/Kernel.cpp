
#include "..\..\code\headers\Kernel.h"



namespace engine 
{
	Kernel::Kernel() 
	{
		isActive = true;
	}

	void Kernel::Initilize()
	{
		for (auto currentTask : listOfTasks)
		{
			currentTask->Initilize();
		}

		Run();
	}

	void Kernel::Run()
	{
		while (isActive)
		{
			for (auto currentTask : listOfTasks)
			{
				currentTask->Run();
			}
		}

		End();
	}

	void Kernel::End()
	{
		for (auto currentTask : listOfTasks)
		{
			currentTask->End();
		}
	}

	void Kernel::Set_Active(bool state)
	{
		this->isActive = state;
	}

	void Kernel::Add_Task(Task * Task)
	{
		listOfTasks.insert(Task);
	}

}
