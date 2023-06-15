/// Código por:
/// Felipe Vallejo Molina
/// 
/// felipevm07@gmail.com
/// 2023.06


#pragma once


#include <headers/Component.h>
#include <vector>
#include <memory>
#include <string>
#include <headers/Transform.h>


namespace engine
{
	class Scene;

	//Class container of components (similar to empty GameObjects in Unity)
	class Entity
	{
	private:

		// Id and list of the object which will have attachments of components and other containers if needed
		std::string entityId;
		std::vector<Component*> components;
		
		// State of the Entity (object)
		bool isActive = true;

		Transform * myTransform = nullptr;

	public:

		// Constructors and destructor of class
		Entity(std::string & entityID);
		~Entity() {};

		Entity(Scene* scene);
		Entity(Scene* scene, std::string& entityId);
		// Create a child
		Entity(Scene* scene, std::string& entityId, Transform* transform);
		

		std::string Get_Entity_ID();
		void Set_Entity_ID(std::string entityId);

		// With this function we can retrieve a specific component from the entity.
		// T is used for each component created
		//template <typename T>
		//T * Get_Component();

		// Add a component to the entity
		void Add_Component(Component* Component);

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