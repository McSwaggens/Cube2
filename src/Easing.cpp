#include "Easing.h"

#include <cmath>

//?
//? ─── EASING FUNCTIONS ───────────────────────────────────────────────────────────
//?

	//?
	//? ─── QUAD ───────────────────────────────────────────────────────────────────────
	//?

	float Easing::Quad::In (float t)
	{
		return t * t;
	}

	float Easing::Quad::Out (float t)
	{
		return 1-In(1-t);
	}

	float Easing::Quad::InOut (float t)
	{
		return In (t) * Out (t);
	}
	
	//?
	//? ─── CUBIC ──────────────────────────────────────────────────────────────────────
	//?
	
	float Easing::Cubic::In (float t)
	{
		return t * t * t;
	}
	
	float Easing::Cubic::Out (float t)
	{
		return 1 - In (t);
	}
	
	float Easing::Cubic::InOut (float t)
	{
		return t < 0.5 ? 2 * t * t : -1.0f + (4.0f - 2.0f * t) * t;
	}
	
	
	//? ────────────────────────────────────────────────────────────────────────────────


//? ────────────────────────────────────────────────────────────────────────────────
