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

float PerpDot (Vector a, Vector b)
{
	return (a.x * b.y) - (a.y * b.x);
}


//?
//? ─── ROTATION ───────────────────────────────────────────────────────────────────
//?

#define DEGREES 57.2957795131f; // 180 / PI
#define RADIANS 0.01745329251f; // PI / 180

float Angle (Vector a, Vector b)
{
	return acos (Clamp(Dot(a.Normalized(), b.Normalized()), -1.0f, 1.0f)) * DEGREES;
}

float RotationBetween (Vector a, Vector b)
{
	Vector dif = b - a;
	float s = (a.y > b.y) ? -1.0f : 1.0f;
	return (Angle (vright, dif) * s) + -90;
}

float Degrees (float radians)
{
	return radians * DEGREES;
}

float Radians (float degrees)
{
	return degrees * RADIANS;
}


//? ────────────────────────────────────────────────────────────────────────────────
