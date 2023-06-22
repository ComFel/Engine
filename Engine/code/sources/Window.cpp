/// Código por:
/// Felipe Vallejo Molina
/// 
/// felipevm07@gmail.com
/// 2023.01


#pragma once

#include <SDL.h>
#include <iostream>
#include <headers/Window.hpp>
#include <glad/glad.h>
#include <OpenGL.hpp>


namespace engine
{
	
	Window::Window(const std::string& titleWindow, size_t widthWindow, size_t heigthWindow, bool fullScreen) :
		width_Window(widthWindow), heigth_Window(heigthWindow) , full_Screen (fullScreen)
	{
		// Initialize SDL
		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			throw std::runtime_error("Failed to initialize SDL");
		}

		// Create window
		int window_flags = SDL_WINDOW_OPENGL;
		if (fullScreen)
		{
			window_flags |= SDL_WINDOW_FULLSCREEN_DESKTOP;
		}

		window = SDL_CreateWindow(titleWindow.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, widthWindow, heigthWindow, window_flags);

		if (!window)
		{
			throw std::runtime_error("Failed to create window");
		}

		// Create OpenGL context
		context = SDL_GL_CreateContext(window);

		if (!context)
		{
			throw std::runtime_error("Failed to create OpenGL context");
		}
	}
	/*
	Window::Window(const std::string title, unsigned width, unsigned height, bool fullScreen)
	{
		int window_flag = SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL;

		if (fullScreen) window_flag != SDL_WINDOW_FULLSCREEN;

		SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, (int)width, (int)height, window_flag);
	}
	*/

	Window::~Window()
	{
		SDL_GL_DeleteContext(context);
		SDL_DestroyWindow(window);
		SDL_Quit();
	}

	unsigned Window::Get_Window_Width() 
	{
		return (unsigned)this->width_Window;
	}
	
	unsigned Window::Get_Window_Heigth()
	{
		return (unsigned)this->heigth_Window;
	}

	void Window::Clear_Window()
	{
		if (context) glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}
	void Window::Swap_Buffers()
	{
		if (context) SDL_GL_SwapWindow(window);
	}

	void Window::Close_Window()
	{
		SDL_Event event;
		event.type = SDL_QUIT;
		SDL_PushEvent(&event);
	}
	

}