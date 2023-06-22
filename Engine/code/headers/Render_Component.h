/// Código por:
/// Felipe Vallejo Molina
/// 
/// felipevm07@gmail.com
/// 2023.06


#pragma once

#include <headers/Component.h>
#include <Render_Node.hpp>



namespace engine
{
    class Render_Component : public Component
    {
    public:
        virtual glt::Node& Get_Node() = 0;    
    };
}