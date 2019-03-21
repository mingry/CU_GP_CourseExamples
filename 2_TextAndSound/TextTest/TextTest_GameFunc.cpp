#include "TextTest_GameFunc.h"
#include "SDL_image.h"
#include <iostream>
#include <windows.h>
#include "SDL_ttf.h"
#include <atlstr.h>

extern SDL_Renderer* g_renderer;
extern bool g_flag_running;

TTF_Font *game_font1_;
TTF_Font *game_font2_;
SDL_Texture *title_snakegame_en_;
SDL_Texture *title_snakegame_kr_;
SDL_Rect title_snakegame_en_rect_;
SDL_Rect title_snakegame_kr_rect_;

void InitGame()
{
	// 'Snake Game' Title
	{
		game_font1_ = TTF_OpenFont("../Resources/Chlorinp.ttf", 100);
	
		SDL_Color red = { 255, 0, 0, 0 };
		SDL_Surface *tmp_surface = TTF_RenderText_Blended(game_font1_, "Snake Game", red);
	
		title_snakegame_en_rect_.x = 0;
		title_snakegame_en_rect_.y = 0;
		title_snakegame_en_rect_.w = tmp_surface->w;
		title_snakegame_en_rect_.h = tmp_surface->h;

		title_snakegame_en_ = SDL_CreateTextureFromSurface(g_renderer, tmp_surface);
		
		SDL_FreeSurface(tmp_surface);
		TTF_CloseFont(game_font1_);
	}


	// 'πÏ ∞‘¿”' Title
	{
		game_font2_ = TTF_OpenFont("../Resources/arose.ttf", 100);
	
		SDL_Color blue = { 0, 0, 255, 0 };
		SDL_Surface *tmp_surface = TTF_RenderUTF8_Blended(game_font2_, CW2A(L"πÏ ∞‘¿”", CP_UTF8), blue);
	
		title_snakegame_kr_rect_.x = 0;
		title_snakegame_kr_rect_.y = 0;
		title_snakegame_kr_rect_.w = tmp_surface->w;
		title_snakegame_kr_rect_.h = tmp_surface->h;

		title_snakegame_kr_ = SDL_CreateTextureFromSurface(g_renderer, tmp_surface);
		
		SDL_FreeSurface(tmp_surface);
		TTF_CloseFont(game_font2_);
	}

}


void Update()
{
}


void Render()
{
	SDL_SetRenderDrawColor(g_renderer, 255,255,255,255);
	SDL_RenderClear(g_renderer); // clear the renderer to the draw color

	// Draw a "Snake Game"
	{
		SDL_Rect r;
		r.x = 100;
		r.y = 100;
		r.w = title_snakegame_en_rect_.w;
		r.h = title_snakegame_en_rect_.h;
		SDL_RenderCopy(g_renderer, title_snakegame_en_, 0, &r);
	}

	// Draw a "πÏ ∞‘¿”"
	{
		SDL_Rect r;
		r.x = 100;
		r.y = 300;
		r.w = title_snakegame_kr_rect_.w;
		r.h = title_snakegame_kr_rect_.h;
		SDL_RenderCopy(g_renderer, title_snakegame_kr_, 0, &r);
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

		case SDL_KEYDOWN:
		
			break;

		default:
			break;
		}
	}
}



void ClearGame()
{
	SDL_DestroyTexture(title_snakegame_en_);
	SDL_DestroyTexture(title_snakegame_kr_);
}

