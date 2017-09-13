#include "Color.h"

//?
//? ─── GLOBAL COLORS ──────────────────────────────────────────────────────────────
//?

const Color black (0);
const Color white (1);
const Color red (1, 0, 0);
const Color green (0, 1, 0);
const Color blue (0, 0, 1);
const Color pink (1, 0, 1);


//?
//? ─── COLOR ──────────────────────────────────────────────────────────────────────
//?


Color::Color () : Color (1)
{
}

Color::Color (float r) : Color (r, r, r)
{
}

Color::Color (float r, float g, float b) : Color (r, g, b, 1)
{
}

Color::Color (float r, float g, float b, float a)
{
	this->r = r;
	this->g = g;
	this->b = b;
	this->a = a;
}



//? ────────────────────────────────────────────────────────────────────────────────
