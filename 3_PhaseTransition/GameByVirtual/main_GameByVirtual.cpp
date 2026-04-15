
#include "Game.h"
#include "GameIntro.h"
#include "GameStage1.h"
#include "GameEnding.h"


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

	PhaseInterface *game_phases[3];
	game_phases[0] = new Intro;
	game_phases[1] = new Stage1;
	game_phases[2] = new Ending;

	g_current_game_phase = PHASE_INTRO;

	while ( g_flag_running )
	{
		Uint32 cur_time_ms = SDL_GetTicks();

		if ( cur_time_ms-g_last_time_ms < 33 )
			continue;

		game_phases[g_current_game_phase]->HandleEvents();
		game_phases[g_current_game_phase]->Update();
		game_phases[g_current_game_phase]->Render();

		g_last_time_ms = cur_time_ms;
	}

	delete game_phases[0];
	delete game_phases[1];
	delete game_phases[2];

	ClearGame();

	MIX_DestroyMixer(g_mixer);
	MIX_Quit();
	SDL_DestroyRenderer(g_renderer);
	SDL_DestroyWindow(g_window);
	SDL_Quit();



	return 0;
}
