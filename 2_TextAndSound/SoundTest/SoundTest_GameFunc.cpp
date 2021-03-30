#include "SoundTest_GameFunc.h"
#include "SDL_image.h"
#include <windows.h>


SDL_Rect g_button_rect_1;
SDL_Rect g_button_rect_2;

Mix_Music* g_bg_mus;
Mix_Chunk* g_gun_sound;

void InitGame() {
	g_flag_running = true;

	// Buttons
	g_button_rect_1.x = 100;
	g_button_rect_1.y = 100;
	g_button_rect_1.w = 100;
	g_button_rect_1.h = 100;

	g_button_rect_2.x = 300;
	g_button_rect_2.y = 100;
	g_button_rect_2.w = 100;
	g_button_rect_2.h = 100;

	g_bg_mus = Mix_LoadMUS("../../Resources/Kalimba.mp3");
	if (g_bg_mus == 0) {
		std::cout << "Mix_LoadMUS(\"Kalimba.mp3\"): " << Mix_GetError() << std::endl;
	}

	g_gun_sound = Mix_LoadWAV("../../Resources/ray_gun-Mike_Koenig-1169060422.wav");

	Mix_VolumeMusic(128);
}


void Update() {
}


void Render() {
	SDL_SetRenderDrawColor(g_renderer, 255,255,255,255);
	SDL_RenderClear(g_renderer); // clear the renderer to the draw color

	// Button 1
	{
		SDL_SetRenderDrawColor(g_renderer, 255, 0, 0, 0);
		SDL_RenderFillRect(g_renderer, &g_button_rect_1);
	}


	// Button 2
	{
		SDL_SetRenderDrawColor(g_renderer, 0, 0, 255, 0);
		SDL_RenderFillRect(g_renderer, &g_button_rect_2);
	}
	
	SDL_RenderPresent(g_renderer); // draw to the screen

}



void HandleEvents() {
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

				if ( mouse_x > g_button_rect_1.x && 
					mouse_y > g_button_rect_1.y && 
					mouse_x < g_button_rect_1.x+g_button_rect_1.w &&
					mouse_y < g_button_rect_1.y+g_button_rect_1.h  
					)
				{
					std::cout << "Button1 was pushed with the left mouse button." << std::endl;

					Mix_FadeInMusic(g_bg_mus, -1, 2000);
				}
					
				else if ( mouse_x > g_button_rect_2.x && 
					mouse_y > g_button_rect_2.y && 
					mouse_x < g_button_rect_2.x+g_button_rect_1.w &&
					mouse_y < g_button_rect_2.y+g_button_rect_1.h  
					)
				{
					std::cout << "Button2 was pushed with the left mouse button." << std::endl;

					Mix_PlayChannel(-1, g_gun_sound, 0);
				}
					
				
			}

			// If the mouse left button is pressed. 
			else if ( event.button.button == SDL_BUTTON_RIGHT )
			{
				// Get the cursor's x position.
				int mouse_x = event.button.x;
				int mouse_y = event.button.y;

				if ( mouse_x > g_button_rect_1.x && 
					mouse_y > g_button_rect_1.y && 
					mouse_x < g_button_rect_1.x+g_button_rect_1.w &&
					mouse_y < g_button_rect_1.y+g_button_rect_1.h  
					)
				{
					std::cout << "Button1 was pushed with the right mouse button." << std::endl;
					Mix_FadeOutMusic(2000);
				}
			}
			break;

		default:
			break;
		}
	}
}



void ClearGame() {
	Mix_FreeMusic(g_bg_mus);
	Mix_FreeChunk(g_gun_sound);
}

