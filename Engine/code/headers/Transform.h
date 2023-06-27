/// Código por:
/// Felipe Vallejo Molina
/// 
/// felipevm07@gmail.com
/// 2023.06


#pragma once


#include "Component.h"
#include <glm/glm.hpp>

using namespace glm;

namespace engine 
{
	// Class that defines a specific component for a Entity
	// Class that difines a position, rotation and scale variables of an object
	class Transform : public Component
	{
	private:

		// Variables that containes the information needed of position, rotation and scale to work with
		vec3 position;
		vec3 rotation;
		vec3 scale;

		// Parent attachment to the transform component
		Transform * entityParent;

	public:

		// Constructors, one by default, other with specific position and the last one with all sort of information
		Transform();
		Transform(const float posX, const float posY, const float posZ, Transform* const entityParent = nullptr);
		Transform(vec3 pos, vec3 rot, vec3 scale, Transform* const entityParent = nullptr);
		
		// Set component parent link
		void Set_Parent(Transform * parent);

		// Get the matrix made with the variables to create the posible behaviours
		mat4 Get_Matrix() const;

		// Functions to get the specific values of position, rotation and scale associated to the transform component
		vec3 Get_Position() const;
		vec3 Get_Rotation() const;
		vec3 Get_Scale() const;

		// Functions to set the specific values of position, rotation and scale associated to the transform component
		void Set_Position(vec3 position);
		void Set_Rotation(vec3 rotation);
		void Set_Scale(vec3 scale);

		// Functions to set a specific behaviour associated to the transform component (related to movement, position and rotation)
		void Translate(vec3 tranlation);
		void Rotate(vec3 rotation);
	};


}
