// Copyright 2017 Daniel Jones. All Rights Reserved.

/* RayTracing.h
	Description:
		RayTracing CODE
*/

#pragma once

#include "Vector.h"

namespace RayTracing
{
	bool CheckIntersection (Vector a0, Vector a1, Vector b0, Vector b1, Vector& intersect_point);
}