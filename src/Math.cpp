#include "Math.h"


float Clamp (float v, float min, float max)
{
	return v < min ? min : v > max ? max : v;
}