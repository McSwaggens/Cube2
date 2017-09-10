// Copyright 2017 Daniel Jones. All Rights Reserved.

/* Graphics.h
	Description:
		Graphics drawing namespace
*/

#pragma once

#include "Vector.h"
#include "Color.h"
#include "Transform.h"
#include "Material.h"
#include "Camera.h"

//?
//? ─── GRAPHICS ───────────────────────────────────────────────────────────────────
//?


namespace Graphics
{
	void InitGraphics ();
	void DrawQuad (Camera* camera, Transform* transform, Material* material);
	void DrawLineRaw (Vector a, Vector b, Material* material);
	void DrawLine (Camera* camera, Vector a, Vector b, Material* material);
}



//? ────────────────────────────────────────────────────────────────────────────────
