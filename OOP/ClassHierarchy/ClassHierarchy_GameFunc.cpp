#include "ClassHierarchy_GameFunc.h"
#include <windows.h>
#include "SDL_image.h"
#include "Monster.h"
std::vector<Monster> g_monsters;


void InitGame() {
	g_flag_running = true;

	Monster::LoadSpriteSheet();

	g_monsters.resize(50);
}

void AttackAllMonsters() {
	// Attack Monster with random damage 5 ~ 20
	for (auto& m : g_monsters) {
		m.Attacked(rand() % 16 + 5);
	}
}

void HealAllMonsters() {
	// Heal Monster with 10
	for (auto& m : g_monsters) {
		m.Heal(10);
	}
}

void HandleEvents() {
	// Handle Events
	SDL_Event event;

	if (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			g_flag_running = false;
		}
		else if (event.type == SDL_MOUSEBUTTONDOWN) {
			if (event.button.button == SDL_BUTTON_LEFT) {
				AttackAllMonsters();
			}
			if (event.button.button == SDL_BUTTON_RIGHT) {
				HealAllMonsters();	
			}
		}
	}
}

void Update() {
	// Update
	
	for (auto& m : g_monsters) {
		m.Update();
	}

}

void Render() {

	// Background
	SDL_SetRenderDrawColor(g_renderer, 0, 255, 255, 255);
	SDL_RenderClear(g_renderer);

		for (auto& m : g_monsters) {
		m.Render();
	}


	SDL_RenderPresent(g_renderer);
}

void ClearGame() {
	Monster::ClearSpriteSheet();
}