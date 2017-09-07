// Copyright 2017 Daniel Jones. All Rights Reserved.

/* Transform.h
	Description:
		Holds all transform information
		
*/

#pragma once

#include "Vector.h"
#include "OpenGL.h"

//?
//? ─── TRANSFORM ──────────────────────────────────────────────────────────────────
//?

class Transform
{
public:
	
	//?
	//? ─── VARIABLES ──────────────────────────────────────────────────────────────────
	//?
	
	Vector position;
	float rotation;
	Vector scale;
	
	//?
	//? ─── CONSTRUCTORS ───────────────────────────────────────────────────────────────
	//?
	
	Transform ();
	Transform (Vector position, float rotation, Vector scale);
private:
	
};

//? ────────────────────────────────────────────────────────────────────────────────
