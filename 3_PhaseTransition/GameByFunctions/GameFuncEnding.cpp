
#include "GameFuncEnding.h"
#include "GameFuncPhase.h"
#include "SDL_image.h"
#include <iostream>


extern SDL_Window* g_window;
extern SDL_Renderer* g_renderer;
extern bool g_flag_running;
extern int g_current_game_phase;

static SDL_Texture* g_texture_ending; // the SDL_Texture 
static SDL_Rect g_source_rectangle_ending; // the rectangle for source image
static SDL_Rect g_destination_rectangle_ending; // for destination

void Init_Ending()
{
	// For Texture
	
	SDL_Surface* temp_surface = IMG_Load("../Resources/ending.png");
	g_texture_ending = SDL_CreateTextureFromSurface(g_renderer, temp_surface);
	SDL_FreeSurface(temp_surface);

	SDL_QueryTexture(g_texture_ending, NULL, NULL, &g_source_rectangle_ending.w, &g_source_rectangle_ending.h);
	g_destination_rectangle_ending.x = 300;
	g_destination_rectangle_ending.y = 300;
	g_source_rectangle_ending.x = 0;
	g_source_rectangle_ending.y = 0;
	g_destination_rectangle_ending.w = g_source_rectangle_ending.w;
	g_destination_rectangle_ending.h = g_source_rectangle_ending.h;

}

void Update_Ending()
{
}


void Render_Ending()
{
	SDL_SetRenderDrawColor(g_renderer, 255,255,0,255);
	SDL_RenderClear(g_renderer); // clear the renderer to the draw color

    SDL_RenderClear(g_renderer); // clear the renderer to the draw color
	SDL_RenderCopy(g_renderer, g_texture_ending, &g_source_rectangle_ending, &g_destination_rectangle_ending);

	SDL_RenderPresent(g_renderer); // draw to the screen
}



void HandleEvents_Ending()
{
	SDL_Event event;
	if(SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			g_flag_running = false;
			break;

		case SDL_MOUSEBUTTONDOWN:
		
			// If the mouse left button is pressed. 
			if ( event.button.button == SDL_BUTTON_LEFT )
			{
				g_current_game_phase = PHASE_INTRO;
			}
			break;

		default:
			break;
		}
	}
}


void Clear_Ending()
{
	SDL_DestroyTexture(g_texture_ending);
}