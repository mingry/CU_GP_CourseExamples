#pragma once

#include <iostream>
#include <string>
#include "SDL3/SDL.h"
#include "SDL3_mixer/SDL_mixer.h"
#include "SDL3_image/SDL_image.h"

void InitGame();
void HandleEvents();
void Update();
void Render();
void ClearGame();

extern bool g_flag_running;
extern SDL_Renderer* g_renderer;
extern MIX_Mixer* g_mixer;