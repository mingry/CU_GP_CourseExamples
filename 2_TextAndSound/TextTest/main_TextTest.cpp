#include "TextTest_GameFunc.h"


SDL_Window* g_window;
SDL_Renderer* g_renderer;
bool g_flag_running;
Uint64 g_last_time_ms;


int main(int argc, char* argv[]) {

	// Initializing SDL library
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_EVENTS);

	if (TTF_Init()) {
		SDL_Log("SDL_ttf is ready!");
	}
	else {
		SDL_Log("Couldn't initialize SDL_ttf: %s\n", SDL_GetError());
	}

	g_window = SDL_CreateWindow("TTF", 800, 600, 0);
	g_renderer = SDL_CreateRenderer(g_window, NULL);

	InitGame();

	g_last_time_ms = SDL_GetTicks();

	while ( g_flag_running ) 	{

		Uint64 cur_time_ms = SDL_GetTicks();

		if ( cur_time_ms-g_last_time_ms < 33 )
			continue;

		HandleEvents();
		Update();
		Render();

		g_last_time_ms = cur_time_ms;
	}

	SDL_DestroyRenderer(g_renderer);
	SDL_DestroyWindow(g_window);

	ClearGame();
	TTF_Quit();
	SDL_Quit();
	SDL_DestroyRenderer(g_renderer);
	SDL_DestroyWindow(g_window);


	return 0;
}


