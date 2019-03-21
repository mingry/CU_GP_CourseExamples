#include "SoundTest_GameFunc.h"
#include "SDL_image.h"
#include <iostream>
#include <windows.h>
#include "SDL_mixer.h"

extern SDL_Renderer* g_renderer;
extern bool g_flag_running;


Mix_Chunk *wave1_;
Mix_Music *music1_;

SDL_Rect button_rect_1_;
SDL_Rect button_rect_2_;

void InitGame()
{
		// Buttons
	button_rect_1_.x = 100;
	button_rect_1_.y = 100;
	button_rect_1_.w = 100;
	button_rect_1_.h = 100;

	button_rect_2_.x = 300;
	button_rect_2_.y = 100;
	button_rect_2_.w = 100;
	button_rect_2_.h = 100;


	
	// Set the music volume 
	Mix_VolumeMusic(128);

	// Load the wave and mp3 files 
	wave1_ = Mix_LoadWAV("../Resources/ray_gun-Mike_Koenig-1169060422.wav");
	if ( wave1_ == NULL ) 
	{
		printf("Couldn't load the wav: %s\n", Mix_GetError());
	}

	music1_=Mix_LoadMUS("../Resources/Kalimba.mp3");
	if(!music1_)
	{
		printf(" %s\n", Mix_GetError());
		// this might be a critical error...
	}

}


void Update()
{
}


void Render()
{
	SDL_SetRenderDrawColor(g_renderer, 255,255,255,255);
	SDL_RenderClear(g_renderer); // clear the renderer to the draw color

	// Button 1
	{
		SDL_SetRenderDrawColor(g_renderer, 255, 0, 0, 0);
		SDL_RenderFillRect(g_renderer, &button_rect_1_);
	}


	// Button 2
	{
		SDL_SetRenderDrawColor(g_renderer, 0, 0, 255, 0);
		SDL_RenderFillRect(g_renderer, &button_rect_2_);
	}
	
	SDL_RenderPresent(g_renderer); // draw to the screen

}



void HandleEvents()
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
				// Get the cursor's x position.
				int mouse_x = event.button.x;
				int mouse_y = event.button.y;

				if ( mouse_x > button_rect_1_.x && 
					mouse_y > button_rect_1_.y && 
					mouse_x < button_rect_1_.x+button_rect_1_.w &&
					mouse_y < button_rect_1_.y+button_rect_1_.h  
					)
				{
					Mix_FadeInMusic(music1_, -1, 2000);
				}
					
				if ( mouse_x > button_rect_2_.x && 
					mouse_y > button_rect_2_.y && 
					mouse_x < button_rect_2_.x+button_rect_1_.w &&
					mouse_y < button_rect_2_.y+button_rect_1_.h  
					)
				{
					Mix_PlayChannel(-1, wave1_, 0);
				}
					
				
			}

			// If the mouse left button is pressed. 
			else if ( event.button.button == SDL_BUTTON_RIGHT )
			{
				// Get the cursor's x position.
				int mouse_x = event.button.x;
				int mouse_y = event.button.y;

				if ( mouse_x > button_rect_1_.x && 
					mouse_y > button_rect_1_.y && 
					mouse_x < button_rect_1_.x+button_rect_1_.w &&
					mouse_y < button_rect_1_.y+button_rect_1_.h  
					)
				{
					Mix_HaltMusic();
				}
			}
			break;

		default:
			break;
		}
	}
}



void ClearGame()
{
	if ( wave1_ ) Mix_FreeChunk(wave1_);
	if ( music1_ ) Mix_FreeMusic(music1_);
}

