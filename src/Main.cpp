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
#include "Camera.h"
#include "Time.h"
#include "Mouse.h"
#include "Window.h"
#include "Material.h"
#include "Math.h"
#include "Vector.h"



// CODE

std::string GetWorkingDirectory ()
{
	char path[FILENAME_MAX];
	getcwd(path, FILENAME_MAX);
	return std::string(path);
}

Camera* camera = new Camera ();
Transform transform_a;
Transform transform_b;

void framebuffer_size_callback (GLFWwindow* _window, int _width, int _height)
{
	glViewport (0, 0, _width, _height);
	Window::resolution.x = _width;
	Window::resolution.y = _height;
}

float movespeed = 10;


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
	Shader* tex_shader = ShaderForge::CreateShader (path + "/src/shaders/Textured.glsl");
	Shader* blend_shader = ShaderForge::CreateShader (path + "/src/shaders/Blend.glsl");
	
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
	
	static const GLfloat g_uv_buffer_data[] =
	{
		0.0f, 0.0f,
		1.0f, 0.0f,
		1.0f, 1.0f,
		
		1.0f, 1.0f,
		0.0f, 1.0f,
		-0.0f, 0.0f,
	};
	
	GLuint UVArrayID;
	glGenVertexArrays(1, &UVArrayID);
	glBindVertexArray(UVArrayID);
	
	
	GLuint uv_buffer;
	glGenBuffers (1, &uv_buffer);
	glBindBuffer (GL_ARRAY_BUFFER, uv_buffer);
	glBufferData (GL_ARRAY_BUFFER, sizeof(g_uv_buffer_data), g_uv_buffer_data, GL_STATIC_DRAW);
	
	
	
	
	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);
	
	GLuint vertex_buffer;
	glGenBuffers (1, &vertex_buffer);
	glBindBuffer (GL_ARRAY_BUFFER, vertex_buffer);
	glBufferData (GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
	
	uint ticks = 0;
	
	glEnable (GL_DEPTH_TEST);
	glEnable (GL_BLEND);
	glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glDepthFunc (GL_LESS);
	
	
	
	Texture* texture_a = new Texture ((path + "/src/textures/tux.png").c_str()); // 1
	Texture* texture_b = new Texture ((path + "/src/textures/bricks.bmp").c_str()); // 2
	
	MATERIAL(Blend)
		M_TEXTURE(tex)
		M_TEXTURE(tex2)
	M_END_INIT(blend_material, blend_shader); 
	
	blend_material.tex.data = texture_a;
	blend_material.tex2.data = texture_b;
	
	//glBindTexture (GL_TEXTURE_2D, texture_a->texture_id);
	//glUniform1i(glGetUniformLocation(tex_shader->program_id, "tex"), 0);
	
	
	transform_b.position = Vector (5, 5);
	transform_a.scale = Vector (1, 1);
	transform_b.scale = Vector (1, 1);
	
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
			transform_a.position.y += movespeed * Time::delta;
		}
		if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
		{
			transform_a.position.y -= movespeed * Time::delta;
		}
		if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
		{
			transform_a.position.x += movespeed * Time::delta;
		}
		if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
		{
			transform_a.position.x -= movespeed * Time::delta;
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
		
		camera->AddZoom(-Mouse::scroll.y);
		
		//pos = Mouse::GetWorldPosition(camera);
		
		
		
		
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
		
		glEnableVertexAttribArray (1);
		glBindBuffer (GL_ARRAY_BUFFER, uv_buffer);
		glVertexAttribPointer
		(
			1,
			2,
			GL_FLOAT,
			GL_FALSE,
			0,
			(void*)0
		);
		
		//glPolygonMode (GL_FRONT_AND_BACK, GL_LINE);
		
		Vector mouse_pos = Mouse::GetWorldPosition(camera);
		
		
		printf ("Angle: %f\n", Radians(RotationBetween(transform_b.position, mouse_pos)));
		
		// transform_b.LocalMove (2 * Time::delta);
		
		transform_a.position = mouse_pos.Normalized () * 3.0f;
		transform_a.rotation = RotationBetween(transform_a.position, mouse_pos);
		
		
		mat4 mvp_a = camera->GenerateMVPMatrix (transform_a);
		blend_material.Enable (mvp_a);
		
		
		
		
		glDrawArrays (GL_TRIANGLES, 0, 6);
		blend_material.Disable ();
		
		
		mat4 mvp_b = camera->GenerateMVPMatrix (transform_b);
		blend_material.Enable (mvp_b);
		glDrawArrays (GL_TRIANGLES, 0, 6);
		blend_material.Disable ();
		
		glDisableVertexAttribArray (0);
		glDisableVertexAttribArray (1);
		
		
		glfwSwapBuffers (window);
		bool window_closed = glfwWindowShouldClose (window);
		
		if (window_closed || glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		{
			looping = false;
		}
	}
	
	shader->Dispose ();
	
	glDeleteBuffers (1, &vertex_buffer);
	glDeleteBuffers (1, &uv_buffer);
	
	glfwTerminate ();
	
	return 0;
}