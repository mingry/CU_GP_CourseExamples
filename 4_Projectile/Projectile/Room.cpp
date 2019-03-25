
#include "Room.h"




Room::Room()
{
	gravitational_acc_y_ = -9.8;	// -9.8 m/s^2

	// World height
	height_ = 50;	// 50m
	
	// World width
	width_ = 90; // 90m
	

	// Fence
	vertical_fence_pos_x_ = 45;
	vertical_fence_height_ = 30;
}


