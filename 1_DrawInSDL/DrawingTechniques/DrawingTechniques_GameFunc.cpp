#include "DrawingTechniques_GameFunc.h"
#include <windows.h>
#include "SDL_image.h"

SDL_Rect g_bg_source_rect;
SDL_Rect g_bg_destination_rect;
SDL_Texture* g_bg_texture;


int g_oryugen_sprite_num;
int g_current_oryugen_id;

SDL_Texture* g_ryu_sheet_texture;
SDL_Rect g_oryugen_source_rects[6];
SDL_Rect g_ryu_destination_rect;

int g_image_mode;
int g_time_mode;


void InitGame() {
	g_flag_running = true;

	// BG
	SDL_Surface* bg_surface = IMG_Load("../../Resources/ddd.jpg");
	g_bg_texture = SDL_CreateTextureFromSurface(g_renderer, bg_surface);
	SDL_FreeSurface(bg_surface);

	g_bg_source_rect.x = 0;
	g_bg_source_rect.y = 0;
	g_bg_source_rect.w = 1280;
	g_bg_source_rect.h = 720;

	g_bg_destination_rect.x = 0;
	g_bg_destination_rect.y = 0;
	g_bg_destination_rect.w = 1280;
	g_bg_destination_rect.h = 720;

	

	// Ryu Character
	g_oryugen_sprite_num = 6;
	g_current_oryugen_id = 0;

	SDL_Surface* ryu_sheet_surface = IMG_Load("../../Resources/60224.png");
	SDL_SetColorKey(ryu_sheet_surface, SDL_TRUE, SDL_MapRGB(ryu_sheet_surface->format, 0, 0, 248));
	
	g_ryu_sheet_texture = SDL_CreateTextureFromSurface(g_renderer, ryu_sheet_surface);
	SDL_FreeSurface(ryu_sheet_surface);

	g_oryugen_source_rects[0] = { 7  , 1647, 69, 140 };
	g_oryugen_source_rects[1] = { 94 , 1647, 76, 140 };
	g_oryugen_source_rects[2] = { 171, 1647, 68, 140 };
	g_oryugen_source_rects[3] = { 240, 1647, 61, 140 };
	g_oryugen_source_rects[4] = { 312, 1647, 54, 140 };
	g_oryugen_source_rects[5] = { 390, 1647, 67, 140 };


	g_ryu_destination_rect.x = 300;
	g_ryu_destination_rect.y = 200;
	g_ryu_destination_rect.w = g_oryugen_source_rects[0].w;
	g_ryu_destination_rect.h = g_oryugen_source_rects[0].h;


	g_image_mode = 0;
	g_time_mode = 0;
}

void HandleEvents() {
	// Handle Events
	SDL_Event event;

	if (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			g_flag_running = false;
		}
		else if (event.type == SDL_MOUSEBUTTONDOWN) {
			if (event.button.button == SDL_BUTTON_LEFT) {
				g_image_mode++;
				if (g_image_mode >= 3) g_image_mode = 0;
			}
			if (event.button.button == SDL_BUTTON_RIGHT) {
				g_time_mode++;
				if (g_time_mode >= 3) g_time_mode = 0;
			}
		}
	}
}

void Update() {
	// Update
	
	g_current_oryugen_id++;
	if (g_current_oryugen_id >= g_oryugen_sprite_num) {
		g_current_oryugen_id = 0;
	}

	if (g_time_mode == 0) {
		g_frame_per_sec = 30;
	}
	else if (g_time_mode == 1) {
		g_frame_per_sec = 15;
	}
	else {
		g_frame_per_sec = 10;
	}

}

void Render() {

	// Background
	SDL_RenderCopy(g_renderer, g_bg_texture, &g_bg_source_rect, &g_bg_destination_rect);

	// Character
	// g_ryu_sheet_texture
	if (g_image_mode == 0) {
		SDL_SetTextureColorMod(g_ryu_sheet_texture, 255, 255, 255);
		SDL_SetTextureAlphaMod(g_ryu_sheet_texture, 255);
	}
	else if (g_image_mode == 1) {
		SDL_SetTextureColorMod(g_ryu_sheet_texture, 255, 255, 0);
		SDL_SetTextureAlphaMod(g_ryu_sheet_texture, 100);
	}
	else {
		SDL_SetTextureColorMod(g_ryu_sheet_texture, 255, 0, 0);
		SDL_SetTextureAlphaMod(g_ryu_sheet_texture, 170);
	}


	// 왼쪽 류
	SDL_Rect r = g_ryu_destination_rect;
	r.w = g_oryugen_source_rects[g_current_oryugen_id].w * 2;	// 2배 크게
	r.h = g_oryugen_source_rects[g_current_oryugen_id].h * 2;	// 2배 크게

	SDL_RenderCopy(g_renderer, 
		g_ryu_sheet_texture, 
		&g_oryugen_source_rects[g_current_oryugen_id], 
		&r);


	// 오른쪽 류
	r.x += 200;	// 위치이동

	SDL_RenderCopyEx(g_renderer,
		g_ryu_sheet_texture,
		&g_oryugen_source_rects[g_current_oryugen_id],
		&r, 
		0, 0, SDL_FLIP_HORIZONTAL);	
	// 좌우 반전, 아래 링크 참조
	// https://wiki.libsdl.org/SDL_RenderCopyEx


	SDL_RenderPresent(g_renderer);
}

void ClearGame() {
	SDL_DestroyTexture(g_ryu_sheet_texture);
	SDL_DestroyTexture(g_bg_texture);
}