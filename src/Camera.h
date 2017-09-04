// Copyright 2017 Daniel Jones. All Rights Reserved.

/* Camera.h
	Description:
		Camera class
*/


#pragma once

#include "Vector.h"

class Camera
{
public:
	Vector position;
	float rotation;
	
	Camera ();
	Vector GetActual ();
	glm::mat4 GetMVPMatrix ();
};