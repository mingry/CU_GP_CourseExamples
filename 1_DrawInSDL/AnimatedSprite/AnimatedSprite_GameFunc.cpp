
#include "AnimatedSprite_GameFunc.h" 
#include "SDL_image.h"
#include <iostream>

extern SDL_Window* g_window;
extern SDL_Renderer* g_renderer;
extern bool g_flag_running;
extern int g_frame_time_ms;


SDL_Texture* g_ryu_texture; //  
SDL_Rect g_orygen_src_rects[6]; // Animtion
SDL_Rect g_orygen_dest_rects;

int g_current_animation_index;

void InitGame()
{
	// // Ryu Sprite Sheet Texture
	SDL_Surface* ryu_surface = IMG_Load("../Resources/60224.png");
	SDL_SetColorKey(ryu_surface, 1, SDL_MapRGB(ryu_surface->format, 0, 0, 248));

	g_ryu_texture = SDL_CreateTextureFromSurface(g_renderer, ryu_surface);
	SDL_FreeSurface(ryu_surface);


	// Oryugen Rect
	{
		static const int src_left_x_list[6] = {7, 94, 171, 240, 312, 390};
		static const int src_right_x_list[6] = {76, 170, 239, 301, 366, 457};

		for ( int i=0; i<6; i++ )
		{
			g_orygen_src_rects[i].x = src_left_x_list[i];
			g_orygen_src_rects[i].y = 1647;

			g_orygen_src_rects[i].w = src_right_x_list[i] - src_left_x_list[i];
			g_orygen_src_rects[i].h = 140;
		}

		
	}

	g_orygen_dest_rects.x = 300;
	g_orygen_dest_rects.y = 200;
	g_orygen_dest_rects.w = g_orygen_src_rects[0].w;
	g_orygen_dest_rects.h = g_orygen_src_rects[0].h;


	g_current_animation_index = 0;
}

void ClearGame()
{
	SDL_DestroyTexture(g_ryu_texture);
}

void Update()
{
	g_current_animation_index++;
	if ( g_current_animation_index >= 6 ) 
		g_current_animation_index = 0;
}

void Render()
{
	SDL_SetRenderDrawColor(g_renderer, 0,255,255,0);
	SDL_RenderClear(g_renderer); // clear the renderer to the draw color

	SDL_RenderCopy(g_renderer, g_ryu_texture, &g_orygen_src_rects[g_current_animation_index], &g_orygen_dest_rects);

	SDL_RenderPresent(g_renderer);
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

		case SDL_KEYDOWN:
			if ( event.key.keysym.sym == SDLK_LEFT )
			{
				g_frame_time_ms += 10;
				std::cout << "frame_time: " << g_frame_time_ms << std::endl;
			}
			else if ( event.key.keysym.sym == SDLK_RIGHT )
			{
				g_frame_time_ms -= 10;
				if ( g_frame_time_ms < 0 ) g_frame_time_ms=0;
				std::cout << "frame_time: " << g_frame_time_ms << std::endl;
			}
			break;

		default:
			break;
		}
	}
}
