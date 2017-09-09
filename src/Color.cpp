#include "Color.h"

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
