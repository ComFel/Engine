#pragma once


#include <headers/Component.h>
#include <vector>
#include <memory>
#include <string>


namespace engine
{
	//Class container of components (similar to empty GameObjects in Unity)
	class Entity
	{
	private:

		std::string entityId;
		std::vector<std::unique_ptr<Component>> components;

		bool isActive = true;

	public:

		Entity();
		~Entity() {};

		std::string Get_Entity_ID() const;

		template <typename T>
		T * Get_Component();

		void Add_Component(std::unique_ptr<Component> Component);

		virtual void Initilize();
		virtual void Update();
		virtual void Render();

		void Set_Entity_Status(bool state);

		bool Get_Entity_Status() const;
	};
}