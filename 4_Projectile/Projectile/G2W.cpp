#include "G2W.h"

float G2W_Scale = 300.f;
float W2G_Scale = 1.f / 300.0f;

int G2W_X(float g_x)
{
	return (int)(g_x * G2W_Scale + 500);
}

int G2W_Y(float g_y)
{
	return (int)(-1 * g_y * G2W_Scale + 650);
}

float W2G_X(int w_x)
{
	return (w_x - 500.f) * W2G_Scale;
}

float W2G_Y(int w_y)
{
	return (w_y - 650.f) * -1 * W2G_Scale;
}

