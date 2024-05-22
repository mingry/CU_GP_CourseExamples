#pragma once

// From Game Coordinate(meter) to Window Coordinate(pixel)
int G2W_X(double g_x);
int G2W_Y(double g_y);
extern double G2W_Scale;

// From Window Coordinate(pixel) to Game Coordinate(meter)
double W2G_X(int w_x);
double W2G_Y(int w_y);
extern double W2G_Scale;

