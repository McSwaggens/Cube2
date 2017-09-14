// Copyright 2017 Daniel Jones. All Rights Reserved.

/* Mouse.h
	Description:
		Contains all mouse functions and variables
*/

#pragma once

#include "Vector.h"
#include "Camera.h"

namespace Mouse
{
	extern Vector scroll;
	extern Vector screen_position;
	
	void Initialize ();
	void Update ();
	Vector GetWorldPosition (Camera* camera);
}