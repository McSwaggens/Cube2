// Copyright 2017 Daniel Jones. All Rights Reserved.

/* Math.h
	Description:
		Math functions
*/

#pragma once

#include "Vector.h"
#include <cmath>

//?
//? ─── CLAMP ──────────────────────────────────────────────────────────────────────
//?


float Clamp (float v, float min, float max);
Vector Clamp (Vector v, Vector min, Vector max);
Vector Clamp (Vector v, float min, float max);


//?
//? ─── SIN ────────────────────────────────────────────────────────────────────────
//?


inline float Sin (float v)
{
	return (sin(v));
}

inline Vector Sin (Vector v)
{
	return Vector (sin(v.x), sin(v.y));
}


//?
//? ─── COS ────────────────────────────────────────────────────────────────────────
//?


inline float Cos (float v)
{
	return (cos(v));
}

inline Vector Cos (Vector v)
{
	return Vector (cos(v.x), cos(v.y));
}


//?
//? ─── DOT ────────────────────────────────────────────────────────────────────────
//?


inline float Dot (Vector a, Vector b)
{
	a.x * b.x + a.y * b.y;
}

//? ────────────────────────────────────────────────────────────────────────────────
