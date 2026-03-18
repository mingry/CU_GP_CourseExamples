#pragma once

#include <string>
#include <vector>
#include "SDL3/SDL.h"

class Monster {
public:
	Monster();
	Monster(std::string name);
	
	void Attacked(int damage);
	void Heal(int heal_amount);

	void Update();
	void Render();

	static void LoadSpriteSheet();
	static void ClearSpriteSheet();

private:
	float pos_x;
	float pos_y;
	int health;
	std::string name;
	int cur_sprite_id;

	static std::vector<SDL_FRect> sprite_rects;
	static SDL_Texture* sheet_texture;

};



