#pragma once

#include "SDL.h"

class FreeFallGame
{
public:
	FreeFallGame();
	~FreeFallGame();
	void Render();	
	void Update();
	void HandleEvents();

protected:

	// Ball Texture
	SDL_Texture* ball_texture_; 
	SDL_Rect ball_src_rectangle_;

	bool start_; 
	float ball_pos_[2];
	float ball_vel_[2];
	float ball_radius_;
	
	// Mouse
	int mouse_win_x_;
	int mouse_win_y_;
};

