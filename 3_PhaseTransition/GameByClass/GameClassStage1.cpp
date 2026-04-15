#include "GameClass.h"
#include "GameClassStage1.h"

Stage1::Stage1()
{
	// For Character
	character_go_left_ = false;
	character_go_right_ = false;
	character_x_ = 300;
	character_y_ = 300;


	// For Texture
	
	SDL_Surface* temp_surface = IMG_Load("../../Resources/angry_prof.png");
	texture_ = SDL_CreateTextureFromSurface(g_renderer, temp_surface);
	SDL_DestroySurface(temp_surface);

	SDL_GetTextureSize(texture_, &source_rectangle_.w, &source_rectangle_.h);
	source_rectangle_.x = 0;
	source_rectangle_.y = 0;
	destination_rectangle_.x = (float)character_x_; 
	destination_rectangle_.y = (float)character_y_; 
	destination_rectangle_.w = source_rectangle_.w;
	destination_rectangle_.h = source_rectangle_.h;
}

Stage1::~Stage1()
{
	SDL_DestroyTexture(texture_);
}

void Stage1::Update()
{
	if ( character_go_left_ )
	{
		character_x_ -= 10.;
		destination_rectangle_.x = (float)character_x_;
	}

	if ( character_go_right_ )
	{
		character_x_ += 10.;
		destination_rectangle_.x = (float)character_x_;
	}

}


void Stage1::Render()
{
	SDL_SetRenderDrawColor(g_renderer, 0,255,255,0);
	SDL_RenderClear(g_renderer); // clear the renderer to the draw color

	SDL_RenderTexture(g_renderer, texture_, &source_rectangle_, &destination_rectangle_);

	SDL_RenderPresent(g_renderer); // draw to the screen
}



void Stage1::HandleEvents()
{
	SDL_Event event;
	if(SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_EVENT_QUIT:
			g_flag_running = false;
			break;


		case SDL_EVENT_KEY_DOWN:
			// If the left arrow key is pressed. 
			if ( event.key.key == SDLK_LEFT )
			{
				character_go_left_ = true;
			}
			else if ( event.key.key == SDLK_RIGHT )
			{
				character_go_right_ = true;
			}
			break;

		case SDL_EVENT_KEY_UP:
			if ( event.key.key == SDLK_LEFT )
			{
				character_go_left_ = false;
			}
			else if ( event.key.key == SDLK_RIGHT )
			{
				character_go_right_ = false;
			}
			break;
		

		case SDL_EVENT_MOUSE_BUTTON_DOWN:
		
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
