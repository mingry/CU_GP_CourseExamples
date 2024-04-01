
#include "Monster.h"
#include "SDL_image.h"
#include "StaticInClass_GameFunc.h"



SDL_Texture* Monster::sheet_texture = 0;
std::vector<SDL_Rect> Monster::sprite_rects;

void Monster::LoadSpriteSheet()
{

	SDL_Surface* surface = IMG_Load("../../Resources/monster.png");
	sheet_texture = SDL_CreateTextureFromSurface(g_renderer, surface);
	SDL_FreeSurface(surface);


	sprite_rects.push_back({ 0  , 0, 380, 420 });
	sprite_rects.push_back({ 390, 0, 380, 420 });
	sprite_rects.push_back({ 0, 465, 380, 420 });
	
	sprite_rects.push_back({ 390, 465, 380, 420 });
	sprite_rects.push_back({ 390, 465, 380, 420 });
	sprite_rects.push_back({ 390, 465, 380, 420 });

	sprite_rects.push_back({ 820, 465, 380, 420 });
	sprite_rects.push_back({ 820, 465, 380, 420 });
	sprite_rects.push_back({ 820, 465, 380, 420 });

}


void Monster::ClearSpriteSheet()
{
	SDL_DestroyTexture(sheet_texture);
	sprite_rects.clear();
}




Monster::Monster() {
	pos_x = rand() % 900 + 100;
	pos_y = rand() % 400 + 100;
	health = 100;
	name = "noname";
	cur_sprite_id = rand() % sprite_rects.size();
}

Monster::Monster(std::string name) {
	pos_x = rand() % 900 + 100;
	pos_y = rand() % 400 + 100;
	health = 100;
	this->name = name;
	cur_sprite_id = rand() % sprite_rects.size();
}

void Monster::Update()
{
	if (health <= 0) {
		cur_sprite_id = sprite_rects.size()-1;
	}
	else {
		cur_sprite_id++;
		if (cur_sprite_id >= sprite_rects.size()) {
			cur_sprite_id = 0;
		}
	}
	
}

void Monster::Render() {

	SDL_Rect r = { pos_x, pos_y,
		sprite_rects[cur_sprite_id].w*0.2,
		sprite_rects[cur_sprite_id].h*0.2};
	SDL_RenderCopy(g_renderer, sheet_texture, &sprite_rects[cur_sprite_id], &r);

	// hp bar
	SDL_SetRenderDrawColor(g_renderer, 255, 0, 0, 255);
	SDL_Rect hp_bar = { pos_x, pos_y - 10, health, 10 };
	SDL_RenderFillRect(g_renderer, &hp_bar);

	SDL_Rect hp_bar_box = { pos_x, pos_y - 10, 100, 10 };
	SDL_SetRenderDrawColor(g_renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(g_renderer, &hp_bar_box);


}

void Monster::Attacked(int damage) {
	health -= damage;
	if (health <= 0) {
		health = 0;
	}
}

void Monster::Heal(int heal_amount) {
	health += heal_amount;
	if (health >= 100) {
		health = 100;
	}
}
