#pragma once

#include "GameFunc.h"

class Intro : public PhaseInterface
{
public:
	Intro();
	~Intro();

	virtual void HandleEvents() override;
	virtual void Update() override;
	virtual void Render() override;

private:
	SDL_Texture* texture_intro_; // the SDL_Texture 
	SDL_Rect source_rectangle_intro_; // the rectangle for source image
	SDL_Rect destination_rectangle_intro_; // for destination

};