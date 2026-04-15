
#include "SDL3/SDL.h"
#include <iostream>
#include "GameFunc.h"
#include "GameFuncIntro.h"
#include "GameFuncStage1.h"
#include "GameFuncEnding.h"



/////////////////////////////////////////////////
// Declaration
SDL_Window* g_window;
SDL_Renderer* g_renderer;
bool g_flag_running;
Uint32 g_last_time_ms;
MIX_Mixer* g_mixer;


// Game Phases
int g_current_game_phase;


int main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_EVENTS);
	TTF_Init();

	g_mixer = MIX_CreateMixerDevice(SDL_AUDIO_DEVICE_DEFAULT_PLAYBACK, NULL);


	g_window = SDL_CreateWindow("First Window", 1000, 700, 0);
	g_renderer = SDL_CreateRenderer(g_window, NULL);

	InitGame();
	Init_Intro();
	Init_Stage1();
	Init_Ending();

	g_current_game_phase = PHASE_INTRO;

	g_last_time_ms = SDL_GetTicks();

	while ( g_flag_running )
	{
		Uint32 cur_time_ms = SDL_GetTicks();
		if ( cur_time_ms-g_last_time_ms < 33 )
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
	ClearGame();


	MIX_DestroyMixer(g_mixer);
	MIX_Quit();
	SDL_DestroyRenderer(g_renderer);
	SDL_DestroyWindow(g_window);
	SDL_Quit();


	return 0;
}


