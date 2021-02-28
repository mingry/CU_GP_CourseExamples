#include<iostream>
#include<string>
#include "SDL.h"

int main(int argc, char* argv[]) {

	int input = 0;
	std::string output;

	// Initializing SDL library
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window *window = SDL_CreateWindow("First Window", 100, 100, 800, 600, 0);

	while (true) {

		// Handle Events
		SDL_Event event;
		
		if (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				break;
			}
			else if (event.type == SDL_KEYDOWN) {
				if (event.key.keysym.sym == SDLK_LEFT) {
					input = 1;
				}
				else if (event.key.keysym.sym == SDLK_RIGHT) {
					input = 2;
				}
				else if (event.key.keysym.sym == SDLK_SPACE) {
					input = 3;
				}
			}
			else if (event.type == SDL_KEYUP) {
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