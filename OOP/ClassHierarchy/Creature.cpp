
#include "Creature.h"
#include "SDL_image.h"
#include "ClassHierarchy_GameFunc.h"





Creature::Creature() {
	pos_x = rand() % 900 + 100;
	pos_y = rand() % 400 + 100;
	health = 1.0;
	attack_power = 0.1;
	name = "noname";
}

Creature::Creature(std::string name) {
	pos_x = rand() % 900 + 100;
	pos_y = rand() % 400 + 100;
	health = 1.0;
	attack_power = 0.1;
	this->name = name;
}

void Creature::Render() {

	


}
