#pragma once

#include <SDL.h>
#include <iostream>
#include "..\..\code\headers\Window.hpp"


namespace engine
{
	Window::Window(const std::string& titleWindow, size_t widthWindow, size_t heigthWindow, bool fullScreen) 
	{
		this->widthWindow  = widthWindow;
		this->heigthWindow = heigthWindow;

		context = nullptr;

		fullScreen = false;

		if (SDL_Init(SDL_INIT_VIDEO) < 0) 
		{
			SDL_Log("SDL2 no pudo iniciar la ventana correctamente");
		}
		else 
		{
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);

			window = SDL_CreateWindow(titleWindow.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, (int)widthWindow, (int)heigthWindow, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
		}

		if (!window) 
		{
			SDL_Log("SDL2 no pudo crear la ventana correctamente");
		}
		else 
		{
			context = SDL_GL_CreateContext(window);
			

			

		}

	}
	

	size_t widthWindow;
	size_t heigthWindow;

	

	SDL_Window* window;
	SDL_GLContext context;


	unsigned Get_Window_Width();
	unsigned Get_Window_Heigth();

	void Clear_Window();
	void Swap_Buffers();
	void Close_Window();
	

}