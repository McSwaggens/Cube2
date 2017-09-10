// Copyright 2017 Daniel Jones. All Rights Reserved.

/* Camera.h
	Description:
		Camera Class
*/


#pragma once

#include "Vector.h"
#include "Transform.h"

class Camera;

extern const Camera* main_camera;

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
	Vector GetReal (Vector v);
	float GetYAspect ();
	glm::mat4 GenerateMVPMatrix (Transform transform);
	glm::mat4 GenerateMVPMatrix (Vector v);
};