
#include "GameFunc.h"
#include "GameFuncEnding.h"



Ending::Ending()
{
	// For Texture
	
	SDL_Surface* temp_surface = IMG_Load("../../Resources/ending.png");
	texture_ending_ = SDL_CreateTextureFromSurface(g_renderer, temp_surface);
	SDL_FreeSurface(temp_surface);

	SDL_QueryTexture(texture_ending_, NULL, NULL, &source_rectangle_ending_.w, &source_rectangle_ending_.h);
	destination_rectangle_ending_.x = 300;
	destination_rectangle_ending_.y = 300;
	source_rectangle_ending_.x = 0;
	source_rectangle_ending_.y = 0;
	destination_rectangle_ending_.w = source_rectangle_ending_.w;
	destination_rectangle_ending_.h = source_rectangle_ending_.h;

}

void Ending::Update()
{
}


void Ending::Render()
{
	SDL_SetRenderDrawColor(g_renderer, 255,255,0,255);
	SDL_RenderClear(g_renderer); // clear the renderer to the draw color

	SDL_RenderCopy(g_renderer, texture_ending_, &source_rectangle_ending_, &destination_rectangle_ending_);

	SDL_RenderPresent(g_renderer); // draw to the screen
}



void Ending::HandleEvents()
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


Ending::~Ending()
{
	SDL_DestroyTexture(texture_ending_);
}