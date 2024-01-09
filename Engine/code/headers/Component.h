/// Código por:
/// Felipe Vallejo Molina
/// 
/// felipevm07@gmail.com
/// 2024.01


#pragma once

namespace engine
{
	//Advance Statement
	class  Entity;
	
	//Class container for a component
	class Component
	{
	protected:

		// Reference to the parent attach to the component
		Entity* myEntity = nullptr;

	public:

		// Set entity parent attachment
		void Set_Entity(Entity * const entity) 
		{
			this->myEntity = entity;
		}

		// Get parent attach to the component
		Entity* Get_Entity()
		{
			return myEntity;
		}
	};
}
