#include "Math.h"
#include <cmath>

//?
//? ─── CLAMP ──────────────────────────────────────────────────────────────────────
//?


float Clamp (float v, float min, float max)
{
	return v < min ? min : v > max ? max : v;
}

Vector Clamp (Vector v, Vector min, Vector max)
{
	return v < min ? min : v > max ? max : v;
}

Vector Clamp (Vector v, float min, float max)
{
	return v < min ? min : v > max ? max : v;
}


//? ────────────────────────────────────────────────────────────────────────────────
