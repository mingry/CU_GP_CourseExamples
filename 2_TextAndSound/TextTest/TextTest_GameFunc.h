#pragma once

#include <iostream>
#include <string>
#include "SDL3/SDL.h"
#include "SDL3_ttf/SDL_ttf.h"


void InitGame();
void HandleEvents();
void Update();
void Render();
void ClearGame();

extern bool g_flag_running;
extern SDL_Renderer* g_renderer;