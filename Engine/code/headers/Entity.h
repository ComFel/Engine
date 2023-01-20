/// Código por:
/// Felipe Vallejo Molina
/// 
/// felipevm07@gmail.com
/// 2023.01


#pragma once


#include <headers/Component.h>
#include <vector>
#include <memory>
#include <string>
#include <headers/Transform.h>


namespace engine
{
	//Class container of components (similar to empty GameObjects in Unity)
	class Entity
	{
	private:

		// Id and list of the object which will have attachments of components and other containers if needed
		std::string entityId;
		std::vector<std::unique_ptr<Component>> components;
		
		// State of the Entity (object)
		bool isActive = true;

		Transform * myTransform = nullptr;

	public:

		// Constructor and destructor of class
		Entity(std::string & entityID);
		~Entity() {};

		std::string Get_Entity_ID() const;

		// With this function we can retrieve a specific component from the entity.
		// T is used for each component created
		template <typename T>
		T * Get_Component();

		// Add a component to the entity
		void Add_Component(std::unique_ptr<Component> Component);

		virtual void Initilize();
		virtual void Update();
		virtual void Render();

		// Set entity status
		void Set_Entity_Status(bool state);

		// Check entity status
		bool Get_Entity_Status() const;

		// Get the position and information of the entity
		Transform * Get_Transform();
	};
}