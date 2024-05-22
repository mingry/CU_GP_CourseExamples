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
	double ball_pos_[2];
	double ball_vel_[2];
	double ball_radius_;
	
	// Mouse
	int mouse_win_x_;
	int mouse_win_y_;
};

