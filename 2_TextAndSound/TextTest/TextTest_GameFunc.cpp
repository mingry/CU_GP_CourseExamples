#include "TextTest_GameFunc.h"
#include "SDL_image.h"
//#include <windows.h>
//#include <atlstr.h> // for CW2A fuction


SDL_Texture* g_title_en;
SDL_Rect g_title_en_rect;

SDL_Texture* g_title_kr;
SDL_Rect g_title_kr_rect;


void InitGame() {

	g_flag_running = true;

	// English Title
	{
		TTF_Font* font1 = TTF_OpenFont("../../Resources/Chlorinp.ttf", 100);
		SDL_Color red = { 255, 0, 0, 0 };
		SDL_Surface* tmp_surface = TTF_RenderText_Blended(font1, "Snake Game", red);

		g_title_en_rect.x = 0;
		g_title_en_rect.y = 0;
		g_title_en_rect.w = tmp_surface->w;
		g_title_en_rect.h = tmp_surface->h;

		g_title_en = SDL_CreateTextureFromSurface(g_renderer, tmp_surface);
		SDL_FreeSurface(tmp_surface);
		TTF_CloseFont(font1);
	}


	// Korean Title
	{
		TTF_Font* font2 = TTF_OpenFont("../../Resources/arose.ttf", 100);
		SDL_Color blue = { 0, 0, 255, 0 };
		
		//SDL_Surface* tmp_surface = TTF_RenderUTF8_Blended(font2, CW2A(L"¹ì °ÔÀÓ", CP_UTF8), blue); // ealier than c++ 11

		std::string str = u8"¹ì °ÔÀÓ";
		SDL_Surface* tmp_surface = TTF_RenderUTF8_Blended(font2, str.c_str(), blue);

		g_title_kr_rect.x = 0;
		g_title_kr_rect.y = 0;
		g_title_kr_rect.w = tmp_surface->w;
		g_title_kr_rect.h = tmp_surface->h;

		g_title_kr = SDL_CreateTextureFromSurface(g_renderer, tmp_surface);
		SDL_FreeSurface(tmp_surface);
		TTF_CloseFont(font2);
	}
}


void Update() {
}


void Render() {

	SDL_SetRenderDrawColor(g_renderer, 255,255,255,255);
	SDL_RenderClear(g_renderer); // clear the renderer to the draw color

	// Draw Title (English)
	{
		SDL_Rect tmp_r;
		tmp_r.x = 100;
		tmp_r.y = 100;
		tmp_r.w = g_title_en_rect.w;
		tmp_r.h = g_title_en_rect.h;
		SDL_RenderCopy(g_renderer, g_title_en, &g_title_en_rect, &tmp_r);
	}

	// Draw Title (Korean)
	{
		SDL_Rect tmp_r;
		tmp_r.x = 100;
		tmp_r.y = 300;
		tmp_r.w = g_title_kr_rect.w;
		tmp_r.h = g_title_kr_rect.h;
		SDL_RenderCopy(g_renderer, g_title_kr, &g_title_kr_rect, &tmp_r);
	}
	
	SDL_RenderPresent(g_renderer); // draw to the screen

}



void HandleEvents() {

	SDL_Event event;
	if(SDL_PollEvent(&event)) {

		switch (event.type) {

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



void ClearGame() {
	SDL_DestroyTexture(g_title_en);
	SDL_DestroyTexture(g_title_kr);
}

