/// Código por:
/// Felipe Vallejo Molina
/// 
/// felipevm07@gmail.com
/// 2023.01



#pragma once

#include <SDL.h>
#include <OpenGL.hpp>
#include "..\headers\Kernel.h"
#include "..\headers\SceneManager.hpp"

using namespace engine;

int main()
{
	//Try move to DemoEngine and got compiled errors
	SceneManager::instance().CreateDemoEngineWindow();


	//while (true)
	//{
	//	//read input : Task
	//	//update
	//	//render
	//	//wait
	//}

	//end

	return 0;
}