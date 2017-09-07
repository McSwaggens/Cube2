// Copyright 2017 Daniel Jones. All Rights Reserved.

/* Camera.h
	Description:
		Camera class
*/


#pragma once

#include "Vector.h"
#include "Transform.h"

class Camera
{
public:
	Vector position;
	float zoom;
	float rotation;
	
	Camera ();
	void AddZoom (float _zoom);
	Vector GetActual ();
	Vector _GetActual ();
	glm::mat4 GenerateMVPMatrix (Transform transform);
};