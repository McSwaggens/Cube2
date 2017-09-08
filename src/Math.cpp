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


//?
//? ─── SIN ────────────────────────────────────────────────────────────────────────
//?


float Sin (float v)
{
	return (sin(v));
}

Vector Sin (Vector v)
{
	return Vector (sin(v.x), sin(v.y));
}


//?
//? ─── COS ────────────────────────────────────────────────────────────────────────
//?


float Cos (float v)
{
	return (cos(v));
}

Vector Cos (Vector v)
{
	return Vector (cos(v.x), cos(v.y));
}


//?
//? ─── DOT ────────────────────────────────────────────────────────────────────────
//?


float Dot (Vector a, Vector b)
{
	return a.x * b.x + a.y * b.y;
}


//? ────────────────────────────────────────────────────────────────────────────────
