#pragma once

// From Game Coordinate(meter) to Window Coordinate(pixel)
float G2W_X(float g_x);
float G2W_Y(float g_y);
extern float G2W_Scale;

// From Window Coordinate(pixel) to Game Coordinate(meter)
float W2G_X(float w_x);
float W2G_Y(float w_y);
extern float W2G_Scale;



