/// Código por:
/// Felipe Vallejo Molina
/// 
/// felipevm07@gmail.com
/// 2023.06

#include <headers/Entity.h>
#include "..\headers\Transform.h"
#include "..\headers\Scene.hpp"

namespace engine 
{
	Entity::Entity(std::string& entityID)
	{
		this->entityId = entityID;		
	}

    Entity::Entity(Scene* scene) 
    {
        this->entityId = "0";
        
        Transform* transform = new Transform();
        this->myTransform = transform;
        Add_Component(transform);

        scene->AddEntittyToScene(this);
    }

    Entity::Entity(Scene* scene, std::string& entityId) 
    {
        this->entityId = entityId;

        Transform* transform = new Transform();
        this->myTransform = transform;
        Add_Component(transform);

        scene->AddEntittyToScene(this);
    }

    Entity::Entity(Scene* scene, std::string& entityId, Transform* transform) 
    {
        this->entityId = entityId;
                
        this->myTransform = new Transform();
        this->myTransform->Set_Parent(transform);

        Add_Component(this->myTransform);
    }

    std::string Entity::Get_Entity_ID()
    {
        return this->entityId;
    }

    void Entity::Set_Entity_ID(std::string entityId)
    {
        this->entityId = entityId;
    }

    //template <typename T>
    //T* Entity::Get_Component()
    //{
    //    for (auto & component : components)
    //    {
    //        // Check if the pointer of the component is the same as the T (template)
    //        if (T * result = dynamic_cast<T *>(component.get()))
    //        {
    //            return result;
    //        }
    //    }
    //    // If the entity dont have any component requested
    //    return nullptr;
    //}

    void Entity::Add_Component(Component* component)
    {
        component->Set_Entity(this);

        // Move the new component to the last position of the list
        components.push_back(component);
    }


    /*void Entity::Initilize()
    {
        for (auto& component : components)
        {
            component->Initilize();
        }
    }

    void Entity::Update()
    {
        for (auto& component : components)
        {
            component->Update();
        }
    }

    void Entity::Render()
    {
        for (auto& component : components)
        {
            component->Render();
        }
    }*/

    void Entity::Set_Entity_Status(bool status)
    {
        this->isActive = status;
    }

    bool Entity::Get_Entity_Status() const
    {
        return this->isActive;
    }

    Transform * Entity::Get_Transform()
    {
        return this->myTransform;
    }
}