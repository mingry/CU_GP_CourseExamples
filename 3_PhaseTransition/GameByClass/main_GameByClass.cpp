
#include "GameClass.h"
#include "GameClassIntro.h"
#include "GameClassStage1.h"
#include "GameClassEnding.h"




/////////////////////////////////////////////////
// Declaration
SDL_Window* g_window;
SDL_Renderer* g_renderer;
bool g_flag_running;
Uint32 g_last_time_ms;

// Game Phases
int g_current_game_phase;

int main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();

	if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 4096) == -1) {
		std::cout << "Mix_OpenAudio " << Mix_GetError() << std::endl;
		exit(1);
	}

	g_window = SDL_CreateWindow("First Window", 100, 100, 1000, 700, 0);
	g_renderer = SDL_CreateRenderer(g_window, -1, 0);


	InitGame();

	Intro intro;
	Stage1 stage1;
	Ending ending;

	g_current_game_phase = PHASE_INTRO;

	while ( g_flag_running )
	{
		Uint32 cur_time_ms = SDL_GetTicks();
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

	SDL_DestroyRenderer(g_renderer);
	SDL_DestroyWindow(g_window);

	Mix_CloseAudio();
	SDL_Quit();


	return 0;
}


