#include "Camera.h"
#include "Math.h"

#include <stdio.h>

using namespace glm;

#define _ASPECT this->zoom, -Y_ASPECT
#define Y_ASPECT ((this->zoom) / (16.0f / 9.0f))

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
	Vector copy = this->_GetActual ();
	
	
	// Center the camera
	copy.x += this->zoom / 2.0f;
	copy.y -= Y_ASPECT / 2.0f;
	
	return copy;
}

Vector Camera::GetReal (Vector v)
{
	vec4 mv = this->GenerateMVPMatrix (v) * vec4(0, 0, 0, 1);
	return Vector (mv.x, mv.y);
}




//TODO: Put model matrix generationa and projection matrix into independant methods

glm::mat4 Camera::GenerateMVPMatrix (Transform transform)
{
	
	mat4 projection = ortho(0.0f, _ASPECT, 0.0f, -1.0f, 1.0f);
	mat4 view;
	mat4 model;
	model = translate(model, vec3(transform.position.x, transform.position.y, 0));
	Vector normalized_camera_position = this->GetActual ();
	model = translate(model, vec3(normalized_camera_position.x, normalized_camera_position.y, 0));
	model = rotate(model, Radians(transform.rotation), vec3(0.0f, 0.0f, 1.0f));
	
	//? Divide the transforms x and y scale by 2, because the vector coordinates are between -1 and +1, the net size of which is 2.
	model = scale(model, vec3(transform.scale.x/2, transform.scale.y/2, 1.0f));
	
	mat4 mvp = projection * view * model;
	
	return mvp;
}

glm::mat4 Camera::GenerateMVPMatrix (Vector v)
{
	mat4 projection = ortho(0.0f, _ASPECT, 0.0f, -1.0f, 1.0f);
	mat4 view;
	mat4 model;
	model = translate(model, vec3(v.x, v.y, 0));
	Vector normalized_camera_position = this->GetActual ();
	model = translate(model, vec3(normalized_camera_position.x, normalized_camera_position.y, 0));
	mat4 mvp = projection * view * model;
	
	return mvp;
}