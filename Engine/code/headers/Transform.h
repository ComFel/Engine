/// Código por:
/// Felipe Vallejo Molina
/// 
/// felipevm07@gmail.com
/// 2023.06


#pragma once


#include <headers/Component.h>
#include <glm/glm.hpp>

namespace engine 
{
	// Class that defines a specific component for a Entity
	// Class that difines a position, rotation and scale variables of an object
	class Transform : public Component
	{
	private:

		// Variables that containes the information needed of position, rotation and scale to work with
		glm::vec3 position;
		glm::vec3 rotation;
		glm::vec3 scale;

		// Parent attachment to the transform component
		Transform * entityParent;

	public:

		// Constructors, one by default, other with specific position and the last one with all sort of information
		Transform();
		Transform(const float posX, const float posY, const float posZ, Transform* const entityParent = nullptr);
		Transform(glm::vec3 pos, glm::vec3 rot, glm::vec3 scale, Transform* const entityParent = nullptr);
		
		// Set component parent link
		void Set_Parent(Transform * parent);

		// Get the matrix made with the variables to create the posible behaviours
		glm::mat4 Get_Matrix() const;

		// Functions to get the specific values of position, rotation and scale associated to the transform component
		glm::vec3 Get_Position() const;
		glm::vec3 Get_Rotation() const;
		glm::vec3 Get_Scale() const;

		// Functions to set the specific values of position, rotation and scale associated to the transform component
		void Set_Position(glm::vec3 position);
		void Set_Rotation(glm::vec3 rotation);
		void Set_Scale(glm::vec3 scale);

		// Functions to set a specific behaviour associated to the transform component (related to movement, position and rotation)
		void Translate(glm::vec3 tranlation);
		void Rotate(glm::vec3 rotation);
	};


}
