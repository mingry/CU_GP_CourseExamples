#pragma once

#include "SDL.h"
#include "Room.h"
#include "Ball.h"

#define MAX_BALL_NUM 1000

class ProjectileGame
{
public:
	ProjectileGame();
	~ProjectileGame();
	void Render();	
	void Update();
	void HandleEvents();

protected:
	void AddNewBall();

protected:

	// Room
	Room room_;


	// Balls
	int num_of_balls_;
	Ball *balls_[MAX_BALL_NUM];

	// Ball Texture
	SDL_Texture* ball_texture_; 
	SDL_Rect ball_src_rectangle_;

	// Mouse
	int mouse_win_x_;
	int mouse_win_y_;

	
};