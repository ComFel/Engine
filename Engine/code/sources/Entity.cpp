/// Código por:
/// Felipe Vallejo Molina
/// 
/// felipevm07@gmail.com
/// 2023.01

#include <headers/Entity.h>

namespace engine 
{
	Entity::Entity(std::string& entityID)
	{
		this->entityId = entityID;		
	}

    std::string Entity::Get_Entity_ID() const
    {
        return this->entityId;
    }

    template <typename T>
    T* Entity::Get_Component()
    {
        for (auto & component : components)
        {
            // Check if the pointer of the component is the same as the T (template)
            if (T * result = dynamic_cast<T *>(component.get()))
            {
                return result;
            }
        }
        // If the entity dont have any component requested
        return nullptr;
    }

    void Entity::Add_Component(std::unique_ptr<Component> component)
    {
        component->Set_Entity(this);

        // Move the new component to the last position of the list
        components.push_back(std::move(component));
    }


    void Entity::Initilize()
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
    }

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