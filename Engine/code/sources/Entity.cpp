

#include <headers/Entity.h>

namespace engine 
{
	Entity::Entity() 
	{
		this->entityId = "0";		
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
            if (T * result = dynamic_cast<T *>(component.get()))
            {
                return result;
            }
        }
        return nullptr;
    }

    void Entity::Add_Component(std::unique_ptr<Component> component)
    {
        component->Set_Entity(this);
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

}