/// Código por:
/// Felipe Vallejo Molina
/// 
/// felipevm07@gmail.com
/// 2023.01


#pragma once

#include <SDL.h>
#include <iostream>


namespace engine 
{
	// Class to manage the creation of a window with OpenGL and SDL2
	class Window 
	{
	private:

		// Basic window information, width and height
		size_t width_Window;
		size_t heigth_Window;

		// Window mode
		bool full_Screen;

	public:

		// SDL2 references for window and context
		SDL_Window * window;
		SDL_GLContext context;

		// Constructor of class, it takes the basic information for a window to be created, as well as if you want to be full screen mode.
		Window(const std::string & titleWindow, size_t widthWindow, size_t heigthWindow, bool fullScreen);
		~Window();

		unsigned Get_Window_Width();
		unsigned Get_Window_Heigth();

		void Clear_Window();
		void Swap_Buffers();
		void Close_Window();
	};

}
