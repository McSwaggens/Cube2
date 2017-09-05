#include "Camera.h"
#include "Math.h"

#include <stdio.h>


Camera::Camera ()
{
	zoom = 20.0f;
}

void Camera::AddZoom (float _zoom)
{
	this->zoom += _zoom;
	this->zoom = Clamp(this->zoom, 2.0f, 50.0f);
}

Vector Camera::_GetActual ()
{
	Vector copy = position;
	
	// Reverse the cameras X coordinate
	copy.x = copy.x*-1.0f;
	copy.x = copy.x*1.0f;
	
	// Reverse the cameras Y coordinate
	copy.y = copy.y*-1.0f;
	copy.y = copy.y*1.0f;
	
	return copy;
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
	copy.x += this->zoom / 2.0f;
	copy.y -= this->zoom / 2.0f;
	
	return copy;
}