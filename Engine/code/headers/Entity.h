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

	public:

		Entity() {};
		~Entity() {};

		template <typename T>
		T * Get_Component();

		virtual void Initilize();
		virtual void Update();
		virtual void Render();
	};
}