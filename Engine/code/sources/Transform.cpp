/// Código por:
/// Felipe Vallejo Molina
/// 
/// felipevm07@gmail.com
/// 2024.01


#define GLM_GTX_transform

#include <headers/Transform.h>
#include <headers/Entity.h>
#include <glm/gtc/matrix_transform.hpp>


namespace engine
{

	Transform::Transform()
	{
		this->position = glm::vec3(0,0,0);
		this->rotation = glm::vec3(0,0,0);
		this->scale    = glm::vec3(1,1,1);

		this->entityParent = nullptr;
	}	
	
	Transform::Transform(const float posX, const float posY, const float posZ, Transform* const entityParent)
	{
		this->position = glm::vec3(posX,posY,posZ);
		this->rotation = glm::vec3(0,0,0);
		this->scale	   = glm::vec3(1,1,1);

		this->entityParent = entityParent;
	}
	
	Transform::Transform(glm::vec3 pos, glm::vec3 rot, glm::vec3 scale, Transform* const entityParent)
	{
		this->position = pos;
		this->rotation = rot;
		this->scale    = scale;

		this->entityParent = entityParent;
	}

	void Transform::Set_Parent(Transform * const parent)
	{
		this->entityParent = parent;
	}

	glm::mat4 Transform::Get_Matrix() const
	{
		//Identity matrix		
		glm::mat4 matrix(1);


		matrix = glm::translate(matrix, position);
		matrix = glm::rotate(matrix, rotation.x, glm::vec3(1, 0, 0));
		matrix = glm::rotate(matrix, rotation.y, glm::vec3(0, 1, 0));
		matrix = glm::rotate(matrix, rotation.z, glm::vec3(0, 0, 1));
		matrix = glm::scale(matrix, scale);


		if (entityParent)
		{
			return entityParent->Get_Matrix() * matrix;
		}

		return matrix;

	}

	glm::vec3 Transform::Get_Position() const
	{
		return this->position;
	}

	glm::vec3 Transform::Get_Rotation() const
	{
		return this->rotation;
	}

	glm::vec3 Transform::Get_Scale() const 
	{
		return this->scale;
	}

	void Transform::Set_Position(glm::vec3 position)
	{
		this->position = position;
	}
	void Transform::Set_Rotation(glm::vec3 rotation) 
	{
		this->rotation = rotation;
	}
	void Transform::Set_Scale(glm::vec3 scale)
	{
		this->scale = scale;
	}

	void Transform::Translate(glm::vec3 tranlation)
	{
		this->position += tranlation;
	}
	void Transform::Rotate(glm::vec3 rotation)
	{
		this->rotation += rotation;
	}

}