// Copyright 2017 Daniel Jones. All Rights Reserved.

/* Renderer.h
	Description:
		Renders something on the screen at a transforms position
*/

#pragma once

#include "Material.h"
#include "Transform.h"
#include "Camera.h"

typedef enum
{
	RENDERSHAPE_NONE,
	RENDERSHAPE_SQUARE
} RenderShape;


class Renderer
{
public:
	Transform* transform;
	Material* material;
	RenderShape rendershape = RENDERSHAPE_NONE;
	
	bool destroyed = false;
	
	Renderer (Transform* transform, Material* material, RenderShape rendershape);
	~Renderer ();
	
	void Render (Camera* camera);
	
private:
	
	void Square (Camera* camera);
};