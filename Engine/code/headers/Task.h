#pragma once


namespace engine
{
	class Task
	{
	public:

		struct compareTaskPriorities
		{
			bool operator() (const Task* first, const Task* second) const 
			{
				return  first->priority < second->priority; 
			}
		};

	public:

		int priority = 0;

		//Asign by default one priority
		Task(int priority = 0)
		{
			this->priority = priority;
		}

		// Virtual methods (and destructor) so we can use them for dynamic binding in runtime.
		virtual ~Task() = default;

		virtual void Initilize();
		virtual void Run();
		virtual void End();

		bool comparePrior(Task* actual, Task* other)
		{
			return actual->priority < other->priority;
		}

	};
}
