#pragma once


#include <headers/Component.h>
#include <glm/glm.hpp>

namespace engine 
{
	class Transform : public Component
	{
	private:

		glm::vec3 position;
		glm::vec3 rotation;
		glm::vec3 scale;

		Transform * entityParent;

	public:

		Transform();
		Transform(const float posX, const float posY, const float posZ, Transform* const entityParent = nullptr);
		Transform(glm::vec3 pos, glm::vec3 rot, glm::vec3 scale, Transform* const entityParent = nullptr);

		void Set_Parent(Transform * parent);

		glm::mat4 Get_Matrix() const;

		glm::vec3 Get_Position() const;
		glm::vec3 Get_Rotation() const;
		glm::vec3 Get_Scale() const;

		void Set_Position(glm::vec3 position);
		void Set_Rotation(glm::vec3 rotation);
		void Set_Scale(glm::vec3 scale);

		void Translate(glm::vec3 tranlation);
		void Rotate(glm::vec3 rotation);
	};


}
