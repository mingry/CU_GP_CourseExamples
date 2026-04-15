#include "GameFunc.h"
#include "GameFuncIntro.h"


static SDL_Texture* g_texture_intro; // the SDL_Texture 
static SDL_FRect g_source_rectangle_intro; // the rectangle for source image
static SDL_FRect g_destination_rectangle_intro; // for destination

void Init_Intro()
{
	// For Texture
	
	SDL_Surface* temp_surface = IMG_Load("../../Resources/intro.png");
	g_texture_intro = SDL_CreateTextureFromSurface(g_renderer, temp_surface);
	SDL_DestroySurface(temp_surface);

	SDL_GetTextureSize(g_texture_intro, &g_source_rectangle_intro.w, &g_source_rectangle_intro.h);
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

	SDL_RenderTexture(g_renderer, g_texture_intro, &g_source_rectangle_intro, &g_destination_rectangle_intro);

	SDL_RenderPresent(g_renderer); // draw to the screen
}



void HandleEvents_Intro()
{
	SDL_Event event;
	if(SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_EVENT_QUIT:
			g_flag_running = false;
			break;

		case SDL_EVENT_MOUSE_BUTTON_DOWN:
		
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