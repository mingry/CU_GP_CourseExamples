
#include "StopwatchGame_GameFunc.h"


SDL_Window* g_window;
SDL_Renderer* g_renderer;
bool g_flag_running;
Uint32 g_last_time_ms;
MIX_Mixer* g_mixer;


int main(int argc, char* argv[])
{
	// Initializing SDL library
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_EVENTS);

	if (TTF_Init()) {
		SDL_Log("SDL_ttf is ready!");
	}
	else {
		SDL_Log("Couldn't initialize SDL_ttf: %s\n", SDL_GetError());
	}

	if (MIX_Init()) {
		SDL_Log("SDL_mixer is ready!");
	}
	else {
		SDL_Log("MIX_Init failed: %s", SDL_GetError());
	}

	g_mixer = MIX_CreateMixerDevice(SDL_AUDIO_DEVICE_DEFAULT_PLAYBACK, NULL);

	g_window = SDL_CreateWindow("Stopwatch Game", 800, 600, 0);
	g_renderer = SDL_CreateRenderer(g_window, NULL);

	InitGame();

	g_last_time_ms = SDL_GetTicks();

	while ( g_flag_running )
	{
		Uint32 cur_time_ms = SDL_GetTicks();

		if (cur_time_ms - g_last_time_ms < 33)
			continue;

		HandleEvents();
		Update();
		Render();

		g_last_time_ms = cur_time_ms;
	}

	SDL_DestroyRenderer(g_renderer);
	SDL_DestroyWindow(g_window);

	ClearGame();

	MIX_DestroyMixer(g_mixer);
	MIX_Quit();
	TTF_Quit();
	SDL_Quit();
	SDL_DestroyRenderer(g_renderer);
	SDL_DestroyWindow(g_window);


	return 0;
}


