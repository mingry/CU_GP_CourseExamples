#pragma once

#include <string>
#include <vector>
#include "SDL.h"

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
	int pos_x;
	int pos_y;
	int health;
	std::string name;
	int cur_sprite_id;

	static std::vector<SDL_Rect> sprite_rects;
	static SDL_Texture* sheet_texture;

};



