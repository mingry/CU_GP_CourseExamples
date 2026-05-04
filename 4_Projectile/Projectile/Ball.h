#pragma once

#include "SDL3/SDL.h"
#include "Room.h"


class Ball
{
public:
	Ball(float radius, Room* room);

	void Reset();
	virtual void Update(float timestep_s);
	void Launch(float initial_force_x, float initial_force_y);


	void velocity(float x, float y) { v_[0] = x; v_[1] = y; }
	float radius() const { return radius_; }
	float mass() const { return mass_; }
	float coeff_of_restitution() { return coeff_of_restitution_; }

	float pos_x() const { return p_[0]; }
	float pos_y() const { return p_[1]; }

protected:
	Room* room_;
	
	float radius_;	// meter
	float mass_;	// kg
	float coeff_of_restitution_; // from 0 o 1

	// position
	float p_[2];	// x, y

	// velocity
	float v_[2];	// x, y
};

