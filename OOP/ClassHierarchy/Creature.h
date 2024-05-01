#pragma once

#include <string>
#include <vector>
#include "SDL.h"

class Creature {
public:
	Creature();
	Creature(std::string name);
	
	virtual void Render() = 0;
	virtual void GetAttacked(double power) = 0;

private:
	int pos_x;
	int pos_y;
	std::string name;
	double health;
	double attack_power;
};



