#pragma once

#include <iostream>
#include <string>
#include "SDL.h"

void InitGame();
void HandleEvents();
void Update();
void Render();
void ClearGame();

extern bool g_flag_running;