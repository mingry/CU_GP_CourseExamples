#include "Drawing_GameFunc.h"
#include "SDL_image.h"

extern SDL_Renderer* g_renderer;
extern bool g_flag_running;

SDL_Texture* g_ryu_sheet_texture;
SDL_Rect g_source_rect;
SDL_Rect g_destination_rect;

void InitGame()
{
	SDL_Surface* ryu_sheet_surface = IMG_Load("../Resources/60224.png");
	// SDL_SetColorKey(ryu_sheet_surface, 1, SDL_MapRGB(ryu_sheet_surface->format, 0, 0, 248)); // Remove Background Color

	g_ryu_sheet_texture = SDL_CreateTextureFromSurface(g_renderer, ryu_sheet_surface);
	SDL_FreeSurface(ryu_sheet_surface);

	g_source_rect.x = 171;
	g_source_rect.y = 1647;
	g_source_rect.w = 67;
	g_source_rect.h = 140;

	g_destination_rect.x = 300;
	g_destination_rect.y = 200;
	g_destination_rect.w = g_source_rect.w;
	g_destination_rect.h = g_source_rect.h;
}


void Update()
{
}


void Render()
{
	SDL_SetRenderDrawColor(g_renderer, 255,255,0,0);
	SDL_RenderClear(g_renderer); // clear the frame buffer
	SDL_RenderCopy(g_renderer, g_ryu_sheet_texture, &g_source_rect, &g_destination_rect);
	

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
			}
			else if ( event.key.keysym.sym == SDLK_RIGHT )
			{
			}
			break;

		case SDL_KEYUP:
			if ( event.key.keysym.sym == SDLK_LEFT 
				|| event.key.keysym.sym == SDLK_RIGHT )
			{
			}
			break;

		case SDL_MOUSEBUTTONDOWN:
		
			// If the mouse left button is pressed. 
			if ( event.button.button == SDL_BUTTON_LEFT )
			{
			}
			break;

		default:
			break;
		}
	}
}



void ClearGame()
{
	SDL_DestroyTexture(g_ryu_sheet_texture);
}

