
#include "SDL.h"
#include <iostream>
#include "GameFunc.h"




/////////////////////////////////////////////////
// Declaration
SDL_Window* g_window;
SDL_Renderer* g_renderer;
bool g_flag_running;

bool InitializeWindow(const char* title, int xpos, int ypos, int width, int height, int fullscreen);
void ClearWindow();


int main(int argc, char* argv[])
{
	InitializeWindow("First Example", 100, 100, 1000, 700, false);

	InitGame();

	while ( g_flag_running )
	{
		HandleEvents();
		Update();
		Render();

		SDL_Delay(30);	// 30 밀리세컨드 기다린다.
	}

	ClearGame();

	ClearWindow();


	return 0;
}



////////////////////////////////////
// Functions for the Window
bool InitializeWindow(const char* title, int xpos, int ypos, int width, int height, int fullscreen)
{
	int flags = 0;
	if(fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	// attempt to initialize SDL
	if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "SDL init success\n";
		// init the window
		g_window = SDL_CreateWindow(title, xpos, ypos, 
			width, height, flags);

		if(g_window != 0) // window init success
		{
			std::cout << "window creation success\n";
			g_renderer = SDL_CreateRenderer(g_window, -1, 0);
			if(g_renderer != 0) // renderer init success
			{
				std::cout << "renderer creation success\n";
				SDL_SetRenderDrawColor(g_renderer, 
					255,255,255,255);
			}
			else
			{
				std::cout << "renderer init fail\n";
				return false; // renderer init fail
			}
		}
		else
		{
			std::cout << "window init fail\n";
			return false; // window init fail
		}
	}
	else
	{
		std::cout << "SDL init fail\n";
		return false; // SDL init fail
	}
	std::cout << "init success\n";
	g_flag_running = true; // everything inited successfully, start the main loop

	return true;

}



void ClearWindow()
{
	std::cout << "cleaning game\n";
	SDL_DestroyWindow(g_window);
	SDL_DestroyRenderer(g_renderer);
	SDL_Quit();
}