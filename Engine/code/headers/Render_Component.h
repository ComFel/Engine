/// Código por:
/// Felipe Vallejo Molina
/// 
/// felipevm07@gmail.com
/// 2023.01


#pragma once

#include <headers/Component.h>
#include <Render_Node.hpp>



namespace engine
{
    class Render_Component : public Component
    {
        virtual glt::Node& Get_Node() = 0;    
    };
}
//    private:
//        // 3D model data, need something like opengl?
//        Model3D* model;
//        // 3D node in the rendering engine
//        glt::Node* node;
//
//    public:
//        // Constructor
//        Render_Component(Model3D* model) : model(model), node(new glt::Node()) {}
//
//        // Setup or initialization
//        void Initilize() override
//        {
//            // Perform setup for the 3D model and node
//            model->Setup();
//            node->Add(model->GetNode());
//        }
//
//        // Update of the component
//        void Update() override
//        {
//            // Update the 3D model and node
//            model->Update();
//            node->Update();
//        }
//
//        // Render of the logic necesary in case of a visual component
//        void Render() override
//        {
//            // Render the 3D model and node
//            model->Render();
//            node->Render();
//        }
//
//        // Get the 3D node
//        glt::Node& GetNode() override { return *node; }
//    };
//}