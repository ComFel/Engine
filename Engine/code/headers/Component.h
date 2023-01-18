#pragma once

namespace engine
{
	//Advance Statement
	class  Entity;
	
	class Component
	{
	protected:

		Entity* myEntity = nullptr;

	public:

		virtual ~Component() = default;

		virtual void Initilize() = 0;
		virtual void Update()	 = 0;
		virtual void Render()	 = 0;


		void Set_Entity(Entity * const entity) 
		{
			this->myEntity = entity;
		}

		Entity * Get_Entity() const
		{
			return this->myEntity;
		}
	};
}
