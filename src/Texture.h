// Copyright 2017 Daniel Jones. All Rights Reserved.

/* Texture.h
	Description:
		Holds the texture infomation
*/


#pragma once

#include "OpenGL.h"

class Texture
{
public:
	GLuint texture_id;
	
	Texture ();
	Texture (const char* image_location);
};