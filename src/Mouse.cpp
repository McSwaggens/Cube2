#include "Mouse.h"

#include "Window.h"
#include <stdio.h>

Vector Mouse::scroll;
Vector Mouse::screen_position;

void ScrollCallBack (GLFWwindow* window, double x, double y)
{
	Mouse::scroll.x = x;
	Mouse::scroll.y = y;
}

void Mouse::Initialize ()
{
	glfwSetScrollCallback (Window::window, ScrollCallBack);
}

void Mouse::Update ()
{
	double x, y;
	glfwGetCursorPos(Window::window, &x, &y);
	
	Mouse::screen_position.x = x;
	Mouse::screen_position.y = y;
	
	
	
	
	static bool scroll_registered = false;
	
	
	if (scroll_registered)
	{
		Mouse::scroll = Vector();
		scroll_registered = false;
	}
	if (Mouse::scroll.x != 0.0f || Mouse::scroll.y != 0.0f)
	{
		scroll_registered = true;
	}
}

Vector Mouse::GetWorldPosition (Camera* camera)
{
	Vector world_position;
	
	Vector camera_actual = camera->_GetActual ();
	
	world_position.x = (((Mouse::screen_position.x / Window::resolution.x)-0.5f) * camera->zoom)-camera_actual.x;
	world_position.y = (((Mouse::screen_position.y / Window::resolution.y)-0.5f) * -camera->GetYAspect())-camera_actual.y;
	return world_position;
}


