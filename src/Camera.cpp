#include "Camera.h"


Camera::Camera ()
{
	zoom = 10.0f;
}

Vector Camera::GetActual ()
{
	Vector copy = position;
	
	// Reverse the cameras X coordinate
	copy.x = copy.x*-1.0f;
	copy.x = copy.x*1.0f;
	
	// Reverse the cameras Y coordinate
	copy.y = copy.y*-1.0f;
	copy.y = copy.y*1.0f;
	
	
	// Center the camera
	copy.x += this->zoom;
	copy.y -= this->zoom;
	
	return copy;
}