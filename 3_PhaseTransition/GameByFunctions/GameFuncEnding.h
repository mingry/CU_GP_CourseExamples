#pragma once

#include "GameFunc.h"

class Ending : public PhaseInterface
{
public:
	Ending();
	~Ending();

	virtual void HandleEvents() override;
	virtual void Update() override;
	virtual void Render() override;

private:
	SDL_Texture* texture_ending_; // the SDL_Texture 
	SDL_Rect source_rectangle_ending_; // the rectangle for source image
	SDL_Rect destination_rectangle_ending_; // for destination
};

