#include "GameFuncStage1.h"
#include "GameFuncPhase.h"
#include "SDL_image.h"
#include <iostream>


extern SDL_Window* g_window;
extern SDL_Renderer* g_renderer;
extern bool g_flag_running;

static SDL_Texture* g_texture_stage1; // the SDL_Texture 
static SDL_Rect g_source_rectangle_stage1; // the rectangle for source image
static SDL_Rect g_destination_rectangle_stage1; // for destination

static bool g_character_go_left;
static bool g_character_go_right;
static double g_character_x;
static double g_character_y;

void Init_Stage1()
{
	// For Character
	g_character_go_left = false;
	g_character_go_right = false;
	g_character_x = 300;
	g_character_y = 300;


	// For Texture
	
	SDL_Surface* temp_surface = IMG_Load("../Resources/angry_prof.png");
	g_texture_stage1 = SDL_CreateTextureFromSurface(g_renderer, temp_surface);
	SDL_FreeSurface(temp_surface);

	SDL_QueryTexture(g_texture_stage1, NULL, NULL, &g_source_rectangle_stage1.w, &g_source_rectangle_stage1.h);
	g_source_rectangle_stage1.x = 0;
	g_source_rectangle_stage1.y = 0;
	g_destination_rectangle_stage1.x = (int)g_character_x; 
	g_destination_rectangle_stage1.y = (int)g_character_y; 
	g_destination_rectangle_stage1.w = g_source_rectangle_stage1.w;
	g_destination_rectangle_stage1.h = g_source_rectangle_stage1.h;


}

void Update_Stage1()
{
	if ( g_character_go_left )
	{
		g_character_x -= 10.;
		g_destination_rectangle_stage1.x = (int)g_character_x;
	}

	if ( g_character_go_right )
	{
		g_character_x += 10.;
		g_destination_rectangle_stage1.x = (int)g_character_x;
	}
}


void Render_Stage1()
{
	SDL_SetRenderDrawColor(g_renderer, 0,255,255,0);
	SDL_RenderClear(g_renderer); // clear the renderer to the draw color

    SDL_RenderClear(g_renderer); // clear the renderer to the draw color
	SDL_RenderCopy(g_renderer, g_texture_stage1, &g_source_rectangle_stage1, &g_destination_rectangle_stage1);

	SDL_RenderPresent(g_renderer); // draw to the screen
}



void HandleEvents_Stage1()
{
	SDL_Event event;
	if(SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			g_flag_running = false;
			break;

		case SDL_KEYDOWN:
			// If the left arrow key is pressed. 
			if ( event.key.keysym.sym == SDLK_LEFT )
			{
				g_character_go_left = true;
			}
			else if ( event.key.keysym.sym == SDLK_RIGHT )
			{
				g_character_go_right = true;
			}
			break;

		case SDL_KEYUP:
			if ( event.key.keysym.sym == SDLK_LEFT )
			{
				g_character_go_left = false;
			}
			else if ( event.key.keysym.sym == SDLK_RIGHT )
			{
				g_character_go_right = false;
			}
			break;

		case SDL_MOUSEBUTTONDOWN:
		
			// If the mouse left button is pressed. 
			if ( event.button.button == SDL_BUTTON_LEFT )
			{
				g_current_game_phase = PHASE_ENDING;
			}
			break;

		default:
			break;
		}
	}
}



void Clear_Stage1()
{
	SDL_DestroyTexture(g_texture_stage1);
}

