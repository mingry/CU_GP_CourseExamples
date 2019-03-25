#pragma once

#include "SDL.h"

class Stage1
{
public:
	Stage1();
	~Stage1();

	void HandleEvents();
	void Update();
	void Render();

private:
	SDL_Texture* texture_; // the SDL_Texture 
	SDL_Rect source_rectangle_; // the rectangle for source image
	SDL_Rect destination_rectangle_; // for destination

	bool character_go_left_;
	bool character_go_right_;
	double character_x_;
	double character_y_;
};


