// Copyright 2017 Daniel Jones. All Rights Reserved.

/* Math.h
	Description:
		Math functions
*/

#pragma once

#include "Vector.h"
#include <cmath>

#define PI 3.14159265358979323846

//?
//? ─── CLAMP ──────────────────────────────────────────────────────────────────────
//?


float Clamp (float v, float min, float max);
Vector Clamp (Vector v, Vector min, Vector max);
Vector Clamp (Vector v, float min, float max);


//?
//? ─── SIN ────────────────────────────────────────────────────────────────────────
//?


float Sin (float v);

Vector Sin (Vector v);


//?
//? ─── COS ────────────────────────────────────────────────────────────────────────
//?


float Cos (float v);

Vector Cos (Vector v);

//?
//? ─── DOT ────────────────────────────────────────────────────────────────────────
//?


float Dot (Vector a, Vector b);
float PerpDot (Vector a, Vector b);


//?
//? ─── ROTATION ───────────────────────────────────────────────────────────────────
//?


float Angle (Vector a, Vector b);
float RotationBetween (Vector a, Vector b);

float Degrees (float radians);
float Radians (float degrees);


//? ────────────────────────────────────────────────────────────────────────────────
