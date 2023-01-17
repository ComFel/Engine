#pragma once

#include "..\headers\Task.h"
#include <set>

namespace engine 
{
	class Kernel 
	{
	private:

		bool isActive = true;

	public:

		Kernel();

		void Initilize();
		void Run();
		void End();
		void Set_Active(bool state);

		void Add_Task(Task * Task);

		//with Std lib we create a list of pointers to all tasks created so the kernel can see the priority of tasks store into themselfes
		std::set<Task*, Task::compareTaskPriorities> listOfTasks;
	};

}
