#pragma once

#include <SDL.h>
#include <iostream>


namespace engine 
{
	class Window 
	{
	private:

		size_t widthWindow;
		size_t heigthWindow;

	public:

		SDL_Window * window;
		SDL_GLContext context;

		Window(const std::string & titleWindow, size_t widthWindow, size_t heigthWindow, bool fullScreen);
		//~Window();

		unsigned Get_Window_Width();
		unsigned Get_Window_Heigth();

		void Clear_Window();
		void Swap_Buffers();
		void Close_Window();
	};

}
