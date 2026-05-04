#pragma once

#include "SDL3/SDL.h"
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
	SDL_FRect ball_src_rectangle_;

	// Mouse
	float mouse_win_x_;
	float mouse_win_y_;

	
};