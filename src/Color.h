// Copyright 2017 Daniel Jones. All Rights Reserved.

/* Color.h
	Description:
		Color Class
*/

#pragma once

class Color;

//?
//? ─── GLOBAL COLORS ──────────────────────────────────────────────────────────────
//?

extern const Color black;
extern const Color white;
extern const Color red;
extern const Color green;
extern const Color blue;
extern const Color pink;

#define ERROR_COLOR pink

//?
//? ─── COLOR ──────────────────────────────────────────────────────────────────────
//?


class Color
{
public:
	
	float r;
	float g;
	float b;
	float a;
	
	Color ();
	Color (float r);
	Color (float r, float a);
	Color (float r, float g, float b);
	Color (float r, float g, float b, float a);
	
private:
	
};

//? ────────────────────────────────────────────────────────────────────────────────
