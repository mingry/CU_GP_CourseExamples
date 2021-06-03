#pragma once

#include "GameFunc.h"

class Stage1 : public PhaseInterface
{
public:
	Stage1();
	~Stage1();

	virtual void HandleEvents() override;
	virtual void Update() override;
	virtual void Render() override;

private:

	SDL_Texture* texture_stage1_; // the SDL_Texture 
	SDL_Rect source_rectangle_stage1_; // the rectangle for source image
	SDL_Rect destination_rectangle_stage1_; // for destination

	bool character_go_left_;
	bool character_go_right_;
	double character_x_;
	double character_y_;

};



