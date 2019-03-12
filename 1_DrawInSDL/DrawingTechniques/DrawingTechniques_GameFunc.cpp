
#include "DrawingTechniques_GameFunc.h" 
#include "SDL_image.h"
#include <iostream>

extern SDL_Window* g_window;
extern SDL_Renderer* g_renderer;
extern bool g_flag_running;
extern int g_frame_time_ms;


SDL_Rect bg_source_rectangle_; 
SDL_Rect bg_destination_rectangle_;
SDL_Texture* bg_texture_; //  SDL_Texture variable


SDL_Texture* textures_[4]; //  
SDL_Rect source_rectangle_; // first rectangle
SDL_Rect destination_rectangles_[4]; // another rectangle


int oryugen_sprite_num_;
int cur_sprite_index_;
std::vector<SDL_Rect> orygen_source_rectangle_; // first rectangle
SDL_Rect orygen_destiniation_rectangles_[2]; // first rectangle

int image_mode_;
int time_mode_;

void InitGame()
{
	// Back-Ground Texture (bg_texture_)
	{
		SDL_Surface* bg_surface = IMG_Load("../Resources/ddd.jpg");
		bg_destination_rectangle_.x = bg_source_rectangle_.x = 0;
		bg_destination_rectangle_.y = bg_source_rectangle_.y = 0;
		bg_destination_rectangle_.w = bg_source_rectangle_.w = bg_surface->w;
		bg_destination_rectangle_.h = bg_source_rectangle_.h = bg_surface->h;

		bg_texture_ = SDL_CreateTextureFromSurface(g_renderer, bg_surface);
		SDL_FreeSurface(bg_surface);

	}

	// // Ryu Texture
	{
		SDL_Surface* temp_surface = IMG_Load("../Resources/60224.png");

		// Original
		textures_[0] = SDL_CreateTextureFromSurface(g_renderer, temp_surface);
		
		// Back ground Removed
		SDL_SetColorKey(temp_surface, 1, SDL_MapRGB(temp_surface->format, 0, 0, 248));
		textures_[1] = SDL_CreateTextureFromSurface(g_renderer, temp_surface);

		// Alpha (translucence)
		textures_[2] = SDL_CreateTextureFromSurface(g_renderer, temp_surface);
		SDL_SetTextureAlphaMod(textures_[2], 170);
		
		// Red
		textures_[3] = SDL_CreateTextureFromSurface(g_renderer, temp_surface);
		SDL_SetTextureAlphaMod(textures_[3], 170);
		SDL_SetTextureColorMod(textures_[3], 255, 0, 0);

		SDL_FreeSurface(temp_surface);
	}


	source_rectangle_.x = 0; 
	source_rectangle_.y = 1647;

	source_rectangle_.w = 462;
	source_rectangle_.h = 140;

	for ( int i=0; i<4; i ++ )
	{
		destination_rectangles_[i].x = 500; 
		destination_rectangles_[i].y = i*source_rectangle_.h;
		destination_rectangles_[i].w = source_rectangle_.w;
		destination_rectangles_[i].h = source_rectangle_.h;
	}

	// Oryugen
	{
		static const int src_x1_list[6] = {7, 94, 171, 240, 312, 390};
		static const int src_x2_list[6] = {76, 170, 239, 301, 366, 457};

		oryugen_sprite_num_ = 6;
		cur_sprite_index_ = 0;
		for ( int i=0; i<oryugen_sprite_num_; i++ )
		{
			SDL_Rect r;
			r.x = src_x1_list[i]; 
			r.y = source_rectangle_.y;
			r.w = src_x2_list[i]-src_x1_list[i];
			r.h = source_rectangle_.h;
			orygen_source_rectangle_.push_back(r);
		}

		orygen_destiniation_rectangles_[0].x = 100;
		orygen_destiniation_rectangles_[0].y = source_rectangle_.h+30;

		orygen_destiniation_rectangles_[1].x = 250;
		orygen_destiniation_rectangles_[1].y = source_rectangle_.h+30;
	}


	image_mode_ = 1;
	time_mode_ = 0;
}

void ClearGame()
{
	for ( int i=0; i<4; i ++ )
		SDL_DestroyTexture(textures_[i]);
	SDL_DestroyTexture(bg_texture_);
}


void Update()
{

	cur_sprite_index_ = (cur_sprite_index_+1) % oryugen_sprite_num_;
	
	orygen_destiniation_rectangles_[0].w = 2*orygen_source_rectangle_[cur_sprite_index_].w;
	orygen_destiniation_rectangles_[0].h = 2*orygen_source_rectangle_[cur_sprite_index_].h;

	orygen_destiniation_rectangles_[1].w = 2*orygen_source_rectangle_[cur_sprite_index_].w;
	orygen_destiniation_rectangles_[1].h = 2*orygen_source_rectangle_[cur_sprite_index_].h;

}

void Render()
{
	SDL_RenderClear(g_renderer); // clear the renderer to the draw color

	SDL_RenderCopy(g_renderer, bg_texture_, &bg_source_rectangle_, &bg_destination_rectangle_);


	// Sripte Sheet
	for ( int i=0; i<4; i ++ )
		SDL_RenderCopy(g_renderer, textures_[i], &source_rectangle_, &destination_rectangles_[i]);

	// Animation
	SDL_RenderCopy(g_renderer, textures_[image_mode_], &orygen_source_rectangle_[cur_sprite_index_], &orygen_destiniation_rectangles_[0]);
	SDL_RenderCopyEx(g_renderer, textures_[image_mode_], &orygen_source_rectangle_[cur_sprite_index_], &orygen_destiniation_rectangles_[1], 0, 0, SDL_FLIP_HORIZONTAL);

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
			if ( event.button.button == SDL_BUTTON_LEFT )
			{
				image_mode_ ++;
				if ( image_mode_ >= 4 ) image_mode_= 0;
			}
			if ( event.button.button == SDL_BUTTON_RIGHT )
			{
				time_mode_ ++;
				if ( time_mode_ >= 3 ) time_mode_= 0;

				if ( time_mode_ == 1 )
					g_frame_time_ms = 20;
				else if ( time_mode_ == 2 )
					g_frame_time_ms = 120;
				else 
					g_frame_time_ms = 60;
			}
			break;

		default:
			break;
		}
	}
}
