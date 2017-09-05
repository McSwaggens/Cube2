// Copyright 2017 Daniel Jones. All Rights Reserved.

/* Mouse.h
	Description:
		Contains all mouse functions and variables
*/

#pragma once

#include "Vector.h"
#include "Camera.h"
#include "OpenGL.h"

namespace Mouse
{
	extern Vector scroll;
	extern Vector screen_position;
	
	void Initialize (GLFWwindow* window);
	void Update ();
	Vector GetWorldPosition (Camera* camera);
}