/// Código por:
/// Felipe Vallejo Molina
/// 
/// felipevm07@gmail.com
/// 2024.01


#pragma once


namespace engine
{
	class Task
	{
	public:

		// This struct defines a way to compare two tasks by their priority, it is used to sort a container of tasks by their priority
		struct compare_Task_Priorities
		{
			bool operator() (const Task* first, const Task* second) const
			{
				return  first->myPriority < second->myPriority;
			}
		};

	public:

		// Task priority value for managing it after
		int myPriority = 0;

		// Asign by default one myPriority
		Task(int myPriority = 0)
		{
			this->myPriority = myPriority;
		}

		// Virtual methods (and destructor) so we can use them for dynamic binding in runtime.
		virtual ~Task() = default;

		virtual void Initilize();
		virtual void Run();
		virtual void Finalize();

		// Compare tasks priorities to sort them to then use its correct order for the kernel to execute them
		bool compare_Prior(Task* actual, Task* other)
		{
			return actual->myPriority < other->myPriority;
		}

	};
}
