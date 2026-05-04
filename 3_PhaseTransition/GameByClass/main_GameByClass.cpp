
#include "GameClass.h"
#include "GameClassIntro.h"
#include "GameClassStage1.h"
#include "GameClassEnding.h"




/////////////////////////////////////////////////
// Declaration
SDL_Window* g_window;
SDL_Renderer* g_renderer;
bool g_flag_running;
Uint64 g_last_time_ms;
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

	Intro intro;
	Stage1 stage1;
	Ending ending;

	g_current_game_phase = PHASE_INTRO;

	while ( g_flag_running )
	{
		Uint64 cur_time_ms = SDL_GetTicks();
		if ( cur_time_ms-g_last_time_ms < 33 )
			continue;

		if ( g_current_game_phase ==  PHASE_INTRO )
		{
			intro.HandleEvents();
			intro.Update();
			intro.Render();
		}
		else if ( g_current_game_phase == PHASE_STAGE1 )
		{
			stage1.HandleEvents();
			stage1.Update();
			stage1.Render();
		}
		else if ( g_current_game_phase == PHASE_ENDING )
		{
			ending.HandleEvents();
			ending.Update();
			ending.Render();
		}

		g_last_time_ms = cur_time_ms;
	}

	ClearGame();


	MIX_DestroyMixer(g_mixer);
	MIX_Quit();
	SDL_DestroyRenderer(g_renderer);
	SDL_DestroyWindow(g_window);
	SDL_Quit();



	return 0;
}


