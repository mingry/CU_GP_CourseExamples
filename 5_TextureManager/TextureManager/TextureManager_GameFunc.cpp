
#include "TextureManager_GameFunc.h" 
#include "SDL_image.h"
#include <iostream>
#include <string>
#include "TextureManager.h"

extern SDL_Window* g_window;
extern SDL_Renderer* g_renderer;
extern bool g_flag_running;


int oryugen_sprite_num_;
int cur_sprite_index_;
std::string cur_sprite_id_;

std::vector<SDL_Rect> orygen_source_rectangle_; // first rectangle
SDL_Rect orygen_destiniation_rectangles_[2]; // first rectangle

int image_mode_;
int time_mode_;


void
InitGame()
{

	TextureManager *tm = TextureManager::GetSingleton();

	// Back-Ground Texture (bg_texture_)
	tm->LoadTexture("bg", "../Resources/ddd.jpg");

	// // Ryu Texture
	tm->LoadTexture("ryu", "../Resources/60224.png", 0, 0, 248);



	// Oryugen
	{
		oryugen_sprite_num_ = 6;

		static const int src_x1_list[6] = {7, 94, 171, 240, 312, 390};
		static const int src_x2_list[6] = {76, 170, 239, 301, 366, 457};

		tm->AddSpriteRect("oryugen-0", 7  , 1647, 76-7   , 140);
		tm->AddSpriteRect("oryugen-1", 94 , 1647, 170-94 , 140);
		tm->AddSpriteRect("oryugen-2", 171, 1647, 239-171, 140);
		tm->AddSpriteRect("oryugen-3", 240, 1647, 301-240, 140);
		tm->AddSpriteRect("oryugen-4", 312, 1647, 366-312, 140);
		tm->AddSpriteRect("oryugen-5", 390, 1647, 457-390, 140);
	}

	time_mode_ = 0;
	cur_sprite_index_ = 0;
}

void
ClearGame()
{
}

void
Update()
{
	cur_sprite_index_ = (cur_sprite_index_ + 1) % oryugen_sprite_num_;

	// Make a string of name  "orygen-1", "orygen-2"...
	cur_sprite_id_ = "oryugen-" + std::to_string((long long)cur_sprite_index_);

}


void 
Render()
{
	SDL_RenderClear(g_renderer); // clear the renderer to the draw color

	TextureManager *tm = TextureManager::GetSingleton();

	tm->DrawSprite("bg");
	tm->DrawSprite("ryu", cur_sprite_id_, 100, 200);
	tm->DrawSprite("ryu", cur_sprite_id_, 200, 300);
	tm->DrawSprite("ryu", cur_sprite_id_, 300, 200);
	tm->DrawSprite("ryu", cur_sprite_id_, 400, 300);
	tm->DrawSprite("ryu", cur_sprite_id_, 500, 200);

	SDL_RenderPresent(g_renderer); // draw to the screen
}


void 
HandleEvents()
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
			}
			break;

		default:
			break;
		}
	}
}
