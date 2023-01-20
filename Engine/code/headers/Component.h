/// Código por:
/// Felipe Vallejo Molina
/// 
/// felipevm07@gmail.com
/// 2023.01


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

		// Constructor
		virtual ~Component() = default;

		// Setup or initialization
		virtual void Initilize() = 0;

		// Update of the component, physics ... that needs the component
		virtual void Update()	 = 0;

		// Render of the logic necesary in case of a visual component
		virtual void Render()	 = 0;

		// Set entity parent attachment
		void Set_Entity(Entity * const entity) 
		{
			this->myEntity = entity;
		}

		// Get parent attach to the component
		Entity * Get_Entity() const
		{
			return this->myEntity;
		}
	};
}
