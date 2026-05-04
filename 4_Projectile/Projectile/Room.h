#pragma once

#include "SDL3/SDL.h"



class Room 
{
public:
	Room();

	float width() const { return width_; }
	float height() const { return height_; }
	float left_wall_x() const { return -1.0f*width_/2.f; }
	float right_wall_x() const { return width_ / 2.f; }
	float ground_height() const { return 0.0f; }
	float gravitational_acc_y() const { return gravitational_acc_y_; }

	// Fence
	float vertiacal_fence_pos_x() const { return vertical_fence_pos_x_; }
	float vertiacal_fence_height() const { return vertical_fence_height_; }
	

protected:
	
	float width_;
	float height_;


	// Fence
	float vertical_fence_pos_x_;
	float vertical_fence_height_;

	float gravitational_acc_y_;
	
};

