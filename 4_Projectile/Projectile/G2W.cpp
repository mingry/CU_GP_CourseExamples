#include "G2W.h"


int G2W_X(double g_x)
{
	return (int)(8.0 * g_x + 50);
}

int G2W_Y(double g_y)
{
	return (int)(-1 * 8.0 * g_y + 450);
}

double G2W_Scale()
{
	return 8.0;
}


double W2G_X(int w_x)
{
	return ( w_x - 50 ) / 8.0;
}

double W2G_Y(int w_y)
{
	return -1 * ( w_y - 450 ) / 8.0;
}

double W2G_Scale()
{
	return 1.0/8.0;
}