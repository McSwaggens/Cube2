#include "RayTracing.h"

#include "Math.h"

bool RayTracing::CheckIntersection (Vector a0, Vector a1, Vector b0, Vector b1, Vector& intersect_point)
{
	Vector b = a1 - a0;
	Vector d = b1 - b0;
	
	float perp_dot = PerpDot (b, d);
	
	if (perp_dot == 0.0f)
	{
		return false;
	}
	
	Vector c = b0 - a0;
	float t = PerpDot(c, d) / perp_dot;
	
	if (t < 0 || t > 1)
	{
		return false;
	}
	
	float u = PerpDot(c, b) / perp_dot;
	if (u < 0 || u > 1)
	{
		return false;
	}
	
	intersect_point = a0 + t * b;
	
	return true;
}