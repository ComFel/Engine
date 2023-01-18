#pragma once


namespace engine
{
	class Task
	{
	public:

		struct compare_Task_Priorities
		{
			bool operator() (const Task* first, const Task* second) const 
			{
				return  first->myPriority < second->myPriority; 
			}
		};

	public:

		int myPriority = 0;

		//Asign by default one myPriority
		Task(int myPriority = 0)
		{
			this->myPriority = myPriority;
		}

		// Virtual methods (and destructor) so we can use them for dynamic binding in runtime.
		virtual ~Task() = default;

		virtual void Initilize();
		virtual void Run();
		virtual void End();

		bool compare_Prior(Task* actual, Task* other)
		{
			return actual->myPriority < other->myPriority;
		}

	};
}
