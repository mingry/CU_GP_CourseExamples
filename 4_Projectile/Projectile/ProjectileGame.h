#pragma once

#include "SDL.h"
#include "Room.h"
#include "Ball.h"
#include <vector>

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
	std::vector<Ball> balls_;
	
	// Ball Texture
	SDL_Texture* ball_texture_; 
	SDL_Rect ball_src_rectangle_;

	// Mouse
	int mouse_win_x_;
	int mouse_win_y_;

	
};