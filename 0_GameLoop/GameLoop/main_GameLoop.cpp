#include<iostream>
#include<string>
#include "SDL3/SDL.h"

int main(int argc, char* argv[]) {

	int input = 0;
	std::string output;

	// Initializing SDL library
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_EVENTS);
	SDL_Window* window = SDL_CreateWindow("First Game", 800, 600, SDL_WINDOW_RESIZABLE);

	while (true) {

		// Handle Events
		SDL_Event event;
		
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_EVENT_QUIT) {
				SDL_DestroyWindow(window);
				SDL_Quit();
				return 0;
			}
			else if (event.type == SDL_EVENT_KEY_DOWN) {
				if (event.key.key == SDLK_LEFT) {
					input = 1;
				}
				else if (event.key.key == SDLK_RIGHT) {
					input = 2;
				}
				else if (event.key.key == SDLK_SPACE) {
					input = 3;
				}
			}
			else if (event.type == SDL_EVENT_KEY_UP) {
				input = 0;
			}
		}

		
		// Update
		if (input == 1) {
			output = "^__^\n";
		}
		else if (input == 2) {
			output = "0__0\n";
		}
		else if (input == 3) {
			output = "T__T\n";
		}
		else {
			output = "-__-\n";
		}

		// Render
		std::cout << output;
	}

	SDL_DestroyWindow(window);

	return 0;
}