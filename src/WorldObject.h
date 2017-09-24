// Copyright 2017 Daniel Jones. All Rights Reserved.

/* WorldObject.h
	Description:
		This is currently being used as a test
*/

#pragma once

#include "Renderer.h"
#include "Entity.h"
#include "Transform.h"
#include "Material.h"
#include "Defaults.h"

//?
//? ─── WORLD OBJECT ───────────────────────────────────────────────────────────────
//?

class WorldObject : public Entity
{
public:
	Transform transform;
	BlendMaterial material = BlendMaterial(blend_shader);
	Renderer renderer = Renderer(&transform, &material, RENDERSHAPE_SQUARE);
	
	void Start ();
};

//? ────────────────────────────────────────────────────────────────────────────────
