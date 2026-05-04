#include "G2W.h"

float G2W_Scale = 300.0f;
float W2G_Scale = 1.f / 300.0f;

float G2W_X(float g_x)
{
	return g_x * G2W_Scale + 500.0f;
}

float G2W_Y(float g_y)
{
	return -1.0f * g_y * G2W_Scale + 650.0f;
}

float W2G_X(float w_x)
{
	return (w_x - 500.f) * W2G_Scale;
}

float W2G_Y(float w_y)
{
	return (w_y - 650.f) * -1 * W2G_Scale;
}

