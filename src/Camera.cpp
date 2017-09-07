#include "Camera.h"
#include "Math.h"

#include <stdio.h>

using namespace glm;


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

glm::mat4 Camera::GenerateMVPMatrix (Transform transform)
{
	
	mat4 projection = ortho(0.0f, this->zoom, -this->zoom, 0.0f, -1.0f, 1.0f);
	mat4 view;
	mat4 model;
	model = translate(model, vec3(transform.position.x, transform.position.y, 0));
	Vector normalized_camera_position = this->GetActual ();
	model = translate(model, vec3(normalized_camera_position.x, normalized_camera_position.y, 0));
	model = rotate(model, transform.rotation, vec3(0.0f, 0.0f, 1.0f));
	model = scale(model, vec3(transform.scale.x, transform.scale.y, 1.0f));
	mat4 mvp = projection * view * model;
	
	
	return mvp;
}