// Copyright 2017 Daniel Jones. All Rights Reserved.

/* Vector.h
	Description:
		Vector class
*/

#pragma once

#include <glm/glm.hpp>

class Vector
{
public:
	
	float x;
	float y;
	
	Vector ();
	Vector (float x);
	Vector (float x, float y);
	
	glm::vec2 ToGLM ();
	glm::vec3 ToGLM3 ();
};