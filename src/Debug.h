// Copyright 2017 Daniel Jones. All Rights Reserved.

/* Debug.h
	Description:
		Debug namespace
*/

#pragma once

#include "Vector.h"
#include "Color.h"
#include "Camera.h"

//?
//? ─── DEBUG ──────────────────────────────────────────────────────────────────────
//?


namespace Debug
{
	void DrawLine (Camera* camera, Vector a, Vector b, Color color);
	void EngineUpdateStart ();
	void EngineUpdateEnd ();
}

//? ────────────────────────────────────────────────────────────────────────────────
