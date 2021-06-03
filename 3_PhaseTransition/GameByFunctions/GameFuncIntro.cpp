#include "GameFunc.h"
#include "GameFuncIntro.h"


Intro::Intro()
{
	// For Texture
	SDL_Surface* temp_surface = IMG_Load("../../Resources/intro.png");
	texture_intro_ = SDL_CreateTextureFromSurface(g_renderer, temp_surface);
	SDL_FreeSurface(temp_surface);

	SDL_QueryTexture(texture_intro_, NULL, NULL, &source_rectangle_intro_.w, &source_rectangle_intro_.h);
	destination_rectangle_intro_.x = source_rectangle_intro_.x = 0;
	destination_rectangle_intro_.y = source_rectangle_intro_.y = 0;
	destination_rectangle_intro_.w = source_rectangle_intro_.w;
	destination_rectangle_intro_.h = source_rectangle_intro_.h;

}

void Intro::Update()
{
}


void Intro::Render()
{
	SDL_SetRenderDrawColor(g_renderer, 255,255,255,255);
	SDL_RenderClear(g_renderer); // clear the renderer to the draw color

	SDL_RenderCopy(g_renderer, texture_intro_, &source_rectangle_intro_, &destination_rectangle_intro_);

	SDL_RenderPresent(g_renderer); // draw to the screen
}



void Intro::HandleEvents()
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


Intro::~Intro()
{
	SDL_DestroyTexture(texture_intro_);
}