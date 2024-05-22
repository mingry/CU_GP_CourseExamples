#include "G2W.h"

double G2W_Scale = 300.0;
double W2G_Scale = 1.f / 300.0;

int G2W_X(double g_x)
{
	return (int)(g_x * G2W_Scale + 500);
}

int G2W_Y(double g_y)
{
	return (int)(-1*g_y * G2W_Scale + 650);
}

double W2G_X(int w_x)
{
	return (w_x - 500.f) * W2G_Scale;
}

double W2G_Y(int w_y)
{
	return (w_y - 650.f) * -1 * W2G_Scale;
}

