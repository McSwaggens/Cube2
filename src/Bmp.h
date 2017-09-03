// Copyright 2017 Daniel Jones. All Rights Reserved.

/* Bmp.h
	Description:
		Bmp image loader
*/


#pragma once

#include "Texture.h"

namespace BMP
{
	Texture* Load (const char* image_location);
}