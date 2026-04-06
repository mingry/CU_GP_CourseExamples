#include "SoundTest_GameFunc.h"


SDL_FRect g_button_rect_1;
SDL_FRect g_button_rect_2;

MIX_Audio* g_bg_audio;
MIX_Audio* g_gun_audio;
MIX_Track* g_bg_track;
MIX_Track* g_gun_track;

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

	g_bg_audio = MIX_LoadAudio(g_mixer, "../../Resources/Kalimba.mp3", false);
	if (g_bg_audio == 0) {
		std::cout << "Mix_LoadMUS(\"Kalimba.mp3\"): " << SDL_GetError() << std::endl;
	}

	g_gun_audio = MIX_LoadAudio(g_mixer, "../../Resources/ray_gun-Mike_Koenig-1169060422.wav", false);
	if (g_gun_audio == 0) {
		std::cout << "Mix_LoadMUS(\"ray_gun-Mike_Koenig-1169060422.wav\"): " << SDL_GetError() << std::endl;
	}

	g_bg_track = MIX_CreateTrack(g_mixer);
	g_gun_track = MIX_CreateTrack(g_mixer);

	MIX_SetTrackAudio(g_bg_track, g_bg_audio);
	MIX_SetTrackAudio(g_gun_track, g_gun_audio);
	MIX_SetTrackGain(g_bg_track, 0.5f);
}


void Update() {
}


void Render() {
	SDL_SetRenderDrawColor(g_renderer, 255,255,255,255);
	SDL_RenderClear(g_renderer); // clear the renderer to the draw color

	// Button 1
	{
		SDL_SetRenderDrawColor(g_renderer, 255, 0, 0, 255);
		SDL_RenderFillRect(g_renderer, &g_button_rect_1);
	}


	// Button 2
	{
		SDL_SetRenderDrawColor(g_renderer, 0, 0, 255, 255);
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
		case SDL_EVENT_QUIT:
			g_flag_running = false;
			break;

		case SDL_EVENT_MOUSE_BUTTON_DOWN:
			

			// If the mouse left button is pressed. 
			if ( event.button.button == SDL_BUTTON_LEFT )
			{
				// Get the cursor's x position.
				float mouse_x = event.button.x;
				float mouse_y = event.button.y;

				if ( mouse_x > g_button_rect_1.x && 
					mouse_y > g_button_rect_1.y && 
					mouse_x < g_button_rect_1.x+g_button_rect_1.w &&
					mouse_y < g_button_rect_1.y+g_button_rect_1.h  
					)
				{
					std::cout << "Button1 was pushed with the left mouse button." << std::endl;

					SDL_PropertiesID options = SDL_CreateProperties();

					SDL_SetNumberProperty(options, MIX_PROP_PLAY_LOOPS_NUMBER, -1);
					SDL_SetNumberProperty(options, MIX_PROP_PLAY_FADE_IN_MILLISECONDS_NUMBER, 2000);

					MIX_PlayTrack(g_bg_track, options);


					SDL_DestroyProperties(options);
				}
					
				else if ( mouse_x > g_button_rect_2.x && 
					mouse_y > g_button_rect_2.y && 
					mouse_x < g_button_rect_2.x+g_button_rect_1.w &&
					mouse_y < g_button_rect_2.y+g_button_rect_1.h  
					)
				{
					std::cout << "Button2 was pushed with the left mouse button." << std::endl;

					MIX_PlayTrack(g_gun_track, 0);
				}
					
				
			}

			// If the mouse left button is pressed. 
			else if ( event.button.button == SDL_BUTTON_RIGHT )
			{
				// Get the cursor's x position.
				float mouse_x = event.button.x;
				float mouse_y = event.button.y;

				if ( mouse_x > g_button_rect_1.x && 
					mouse_y > g_button_rect_1.y && 
					mouse_x < g_button_rect_1.x+g_button_rect_1.w &&
					mouse_y < g_button_rect_1.y+g_button_rect_1.h  
					)
				{
					std::cout << "Button1 was pushed with the right mouse button." << std::endl;
					MIX_StopTrack(g_bg_track, 0);
				}
			}
			break;

		default:
			break;
		}
	}
}



void ClearGame() {

	MIX_DestroyTrack(g_bg_track);
	MIX_DestroyTrack(g_gun_track);
	MIX_DestroyAudio(g_bg_audio);
	MIX_DestroyAudio(g_gun_audio);
}




