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
	return (a.x * b.x) + (a.y * b.y);
}


//?
//? ─── ROTATION ───────────────────────────────────────────────────────────────────
//?


float Angle (Vector a, Vector b)
{
	return acos (Clamp(Dot(a.Normalized(), b.Normalized()), -1.0f, 1.0f)) * 57.29578f;
}

float RotationBetween (Vector a, Vector b)
{
	Vector dif = b - a;
	float s = (b.y < a.y) ? -1.0f : 1.0f;
	return (Angle (vright, dif) * s) + -90;
}

float Degrees (float radians)
{
	return radians * (180 / PI);
}

float Radians (float degrees)
{
	return degrees * (PI / 180);
}


//? ────────────────────────────────────────────────────────────────────────────────
