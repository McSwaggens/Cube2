// Copyright 2017 Daniel Jones. All Rights Reserved.

/* Main.cpp
	Description:
		Initializes the game engine
*/


// STANDARD
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string>
#include <math.h>

// OPENGL
#include "OpenGL.h"

// Engine
#include "Shader.h"
#include "ShaderCompiler.h"
#include "Bmp.h"
#include "Vector.h"
#include "Camera.h"
#include "Time.h"
#include "Mouse.h"
#include "Window.h"



// CODE

std::string GetWorkingDirectory ()
{
	char path[FILENAME_MAX];
	getcwd(path, FILENAME_MAX);
	return std::string(path);
}

Camera* camera = new Camera ();
Vector pos;

void framebuffer_size_callback (GLFWwindow* _window, int _width, int _height)
{
	glViewport (0, 0, _width, _height);
	Window::resolution.x = _width;
	Window::resolution.y = _height;
}

float movespeed = 4;
#define PI 3.14159265358979323846


void keyCallback (GLFWwindow* window, int key, int scancode, int action, int mods)
{
	
}



int main ()
{
	if (!glfwInit())
	{
		printf ("%i, Could not initialize glfw\n", stderr);
		return -1;
	}
	
	glfwWindowHint (GLFW_SAMPLES, 4);
	glfwWindowHint (GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint (GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint (GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint (GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	
	GLFWwindow* window = glfwCreateWindow (1920, 1080, "Cube2", NULL, NULL);
	
	if (window == NULL)
	{
		
		printf ("%i, Could not create GLFW window\n", stderr);
		
		glfwTerminate ();
		
		return -1;
	}
	
	
	
	glfwMakeContextCurrent (window);
	
	
	glewExperimental = true;
	
	if (glewInit () != GLEW_OK)
	{
		printf ("%i, Could not initialize glew\n", stderr);
		
		return -1;
	}
	
	std::string path = GetWorkingDirectory ();
	Shader* shader = ShaderForge::CreateShader (path + "/src/shaders/test.glsl");
	
	//glfwSetInputMode (window, GLFW_STICKY_KEYS, GL_TRUE);
	
	bool looping = true;
	
	Window::window = window;
	
	glfwSetFramebufferSizeCallback (window, framebuffer_size_callback);
	glfwSetKeyCallback (window, keyCallback);
	Mouse::Initialize(window);
	
	static const GLfloat g_vertex_buffer_data[] =
	{
		-1.0f, -1.0f, 0.0f,
		1.0f, -1.0f, 0.0f,
		1.0f,  1.0f, 0.0f,
		
		1.0f,  1.0f, 0.0f,
		-1.0f, 1.0f, 1.0f,
		-1.0f, -1.0f, 0.0f,
	};
	
	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);
	
	GLuint vertex_buffer;
	glGenBuffers (1, &vertex_buffer);
	glBindBuffer (GL_ARRAY_BUFFER, vertex_buffer);
	glBufferData (GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
	
	uint ticks = 0;
	
	glEnable (GL_DEPTH_TEST);
	glDepthFunc (GL_LESS);
	
	
	BMP::Load ((path + "/src/textures/bricks.bmp").c_str());
	
	
	
	
	
	while (looping)
	{
		ticks++;
		glfwPollEvents ();
		
		glClearColor(0.05f, 0.05f, 0.05f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		// printf ("[Camera] X:%f, Y:%f\n", camera->position.x, camera->position.y);
		// printf ("[Position] X:%f, Y:%f\n", pos.x, pos.y);
		
		
		Time::Update ();
		Mouse::Update ();
		
		
		
		if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
		{
			pos.y += movespeed * Time::delta;
		}
		if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
		{
			pos.y -= movespeed * Time::delta;
		}
		if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
		{
			pos.x += movespeed * Time::delta;
		}
		if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
		{
			pos.x -= movespeed * Time::delta;
		}
		
		
		
		
		if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		{
			camera->position.y += movespeed * Time::delta;
		}
		if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		{
			camera->position.y -= movespeed * Time::delta;
		}
		if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		{
			camera->position.x += movespeed * Time::delta;
		}
		if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		{
			camera->position.x -= movespeed * Time::delta;
		}
		
		camera->AddZoom(Mouse::scroll.y);
		
		pos = Mouse::GetWorldPosition(camera);
		
		
		// MVP
		
		
		mat4 projection = ortho(0.0f, camera->zoom, -camera->zoom, 0.0f, -1.0f, 1.0f);
		mat4 view;
		mat4 model;
		model = translate(model, vec3(pos.x, pos.y, 0));
		Vector normalized_camera_position = camera->GetActual ();
		model = translate(model, vec3(normalized_camera_position.x, normalized_camera_position.y, 0));
		model = rotate(model, (float)(PI*2.0f), vec3(0.0f, 0.0f, 1.0f));
		model = scale(model, vec3(1.0f, 1.0f, 1.0f));
		mat4 mvp = projection * view * model;
		
		shader->Enable (mvp);
		glEnableVertexAttribArray (0);
		glBindBuffer (GL_ARRAY_BUFFER, vertex_buffer);
		glVertexAttribPointer
		(
			0,
			3,
			GL_FLOAT,
			GL_FALSE,
			0,
			(void*)0
		);
		
		
		glPolygonMode (GL_FRONT_AND_BACK, GL_LINE);
		glDrawArrays (GL_TRIANGLES, 0, 6);
		glDisableVertexAttribArray (0);
		shader->Disable ();
		
		
		
		glfwSwapBuffers (window);
		bool window_closed = glfwWindowShouldClose (window);
		
		if (window_closed || glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		{
			looping = false;
		}
	}
	
	shader->Dispose ();
	
	glDeleteBuffers (1, &vertex_buffer);
	
	glfwTerminate ();
	
	return 0;
}