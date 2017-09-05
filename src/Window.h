// Copyright 2017 Daniel Jones. All Rights Reserved.

/* Window.h
	Description:
		Window class
*/

#pragma once

#include "OpenGL.h"
#include "Vector.h"

namespace Window
{
	extern Vector resolution;
	extern GLFWwindow* window;
	
	void Update ();
};