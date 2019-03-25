
#include "SDL.h"
#include <iostream>
#include "GameFuncPhase.h"
#include "GameFuncIntro.h"
#include "GameFuncStage1.h"
#include "GameFuncEnding.h"




/////////////////////////////////////////////////
// Declaration
SDL_Window* g_window;
SDL_Renderer* g_renderer;
bool g_flag_running;
Uint32 g_last_time_ms;
int g_frame_time_ms = 30;

bool InitializeWindow(const char* title, int xpos, int ypos, int width, int height, int fullscreen);
void ClearWindow();


// Game Phases
int g_current_game_phase;

int main(int argc, char* argv[])
{
	InitializeWindow("Game By Function", 100, 100, 1000, 700, false);

	Init_Intro();
	Init_Stage1();
	Init_Ending();

	g_current_game_phase = PHASE_INTRO;

	while ( g_flag_running )
	{
		Uint32 cur_time_ms = SDL_GetTicks();
		if ( cur_time_ms-g_last_time_ms < g_frame_time_ms )
			continue;

		if ( g_current_game_phase ==  PHASE_INTRO )
		{
			HandleEvents_Intro();
			Update_Intro();
			Render_Intro();
		}
		else if ( g_current_game_phase == PHASE_STAGE1 )
		{
			HandleEvents_Stage1();
			Update_Stage1();
			Render_Stage1();
		}
		else if ( g_current_game_phase == PHASE_ENDING )
		{
			HandleEvents_Ending();
			Update_Ending();
			Render_Ending();
		}

		g_last_time_ms = cur_time_ms;

	}

	Clear_Intro();
	Clear_Stage1();
	Clear_Ending();

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