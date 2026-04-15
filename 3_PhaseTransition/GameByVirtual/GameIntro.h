#pragma once

#include "SDL3/SDL.h"


class Intro : public PhaseInterface
{
public:
	Intro();
	~Intro();
	virtual void HandleEvents();
	virtual void Update();
	virtual void Render();

private:
	SDL_Texture* texture_; // the SDL_Texture 
	SDL_FRect source_rectangle_; // the rectangle for source image
	SDL_FRect destination_rectangle_; // for destination
};


