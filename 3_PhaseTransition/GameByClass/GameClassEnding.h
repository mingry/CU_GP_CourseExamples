#pragma once

#include "SDL3/SDL.h"


class Ending
{
public:
	Ending();
	~Ending();
	void HandleEvents();
	void Update();
	void Render();

private:
	SDL_Texture* texture_; // the SDL_Texture 
	SDL_FRect source_rectangle_; // the rectangle for source image
	SDL_FRect destination_rectangle_; // for destination
};


