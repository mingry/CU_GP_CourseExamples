
#include "Room.h"




Room::Room()
{
	gravitational_acc_y_ = -9.8f;	// -9.8 m/s^2

	// World height
	height_ = 2.f;	// 2m
	
	// World width
	width_ = 3.f; // 3m
	

	// Fence
	vertical_fence_pos_x_ = 0.0f;
	vertical_fence_height_ = 1.0f;
}


