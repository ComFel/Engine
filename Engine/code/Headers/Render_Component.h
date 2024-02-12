/// Código por:
/// Felipe Vallejo Molina
/// 
/// felipevm07@gmail.com
/// 2024.01


#pragma once

#include <Component.h>
#include <Render_Node.hpp>



namespace engine
{
    class Render_Component : public Component
    {
    public:
        virtual glt::Node& Get_Node() = 0;    
    };
}