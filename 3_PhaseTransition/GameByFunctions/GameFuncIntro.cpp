#include "GameFuncIntro.h"
#include "GameFuncPhase.h"
#include "SDL_image.h"
#include <iostream>


extern SDL_Window* g_window;
extern SDL_Renderer* g_renderer;
extern bool g_flag_running;
extern int g_current_game_phase;

static SDL_Texture* g_texture_intro; // the SDL_Texture 
static SDL_Rect g_source_rectangle_intro; // the rectangle for source image
static SDL_Rect g_destination_rectangle_intro; // for destination

void Init_Intro()
{
	// For Texture
	
	SDL_Surface* temp_surface = IMG_Load("../Resources/intro.png");
	g_texture_intro = SDL_CreateTextureFromSurface(g_renderer, temp_surface);
	SDL_FreeSurface(temp_surface);

	SDL_QueryTexture(g_texture_intro, NULL, NULL, &g_source_rectangle_intro.w, &g_source_rectangle_intro.h);
	g_destination_rectangle_intro.x = g_source_rectangle_intro.x = 0;
	g_destination_rectangle_intro.y = g_source_rectangle_intro.y = 0;
	g_destination_rectangle_intro.w = g_source_rectangle_intro.w;
	g_destination_rectangle_intro.h = g_source_rectangle_intro.h;

}

void Update_Intro()
{
}


void Render_Intro()
{
	SDL_SetRenderDrawColor(g_renderer, 255,255,255,255);
	SDL_RenderClear(g_renderer); // clear the renderer to the draw color

    SDL_RenderClear(g_renderer); // clear the renderer to the draw color
	SDL_RenderCopy(g_renderer, g_texture_intro, &g_source_rectangle_intro, &g_destination_rectangle_intro);

	SDL_RenderPresent(g_renderer); // draw to the screen
}



void HandleEvents_Intro()
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
				g_current_game_phase = PHASE_STAGE1;
			}
			break;

		default:
			break;
		}
	}
}


void Clear_Intro()
{
	SDL_DestroyTexture(g_texture_intro);
}