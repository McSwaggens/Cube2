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



// CODE

std::string GetWorkingDirectory ()
{
	char path[FILENAME_MAX];
	getcwd(path, FILENAME_MAX);
	return std::string(path);
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
	
	GLFWwindow* window = glfwCreateWindow (1920, 1080, "DXEngine", NULL, NULL);
	
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
	
	GLuint vertex_array_id;
	glGenVertexArrays (1, &vertex_array_id);
	glBindVertexArray (vertex_array_id);
	
	static const GLfloat cube_vertex_buffer[] =
	{
		-1.0f,-1.0f,-1.0f, // triangle 1 : begin
		-1.0f,-1.0f, 1.0f,
		-1.0f, 1.0f, 1.0f, // triangle 1 : end
		1.0f, 1.0f,-1.0f, // triangle 2 : begin
		-1.0f,-1.0f,-1.0f,
		-1.0f, 1.0f,-1.0f, // triangle 2 : end
		1.0f,-1.0f, 1.0f,
		-1.0f,-1.0f,-1.0f,
		1.0f,-1.0f,-1.0f,
		1.0f, 1.0f,-1.0f,
		1.0f,-1.0f,-1.0f,
		-1.0f,-1.0f,-1.0f,
		-1.0f,-1.0f,-1.0f,
		-1.0f, 1.0f, 1.0f,
		-1.0f, 1.0f,-1.0f,
		1.0f,-1.0f, 1.0f,
		-1.0f,-1.0f, 1.0f,
		-1.0f,-1.0f,-1.0f,
		-1.0f, 1.0f, 1.0f,
		-1.0f,-1.0f, 1.0f,
		1.0f,-1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f,-1.0f,-1.0f,
		1.0f, 1.0f,-1.0f,
		1.0f,-1.0f,-1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f,-1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f,-1.0f,
		-1.0f, 1.0f,-1.0f,
		1.0f, 1.0f, 1.0f,
		-1.0f, 1.0f,-1.0f,
		-1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		-1.0f, 1.0f, 1.0f,
		1.0f,-1.0f, 1.0f
	};
	
	GLuint vertex_buffer_id;
	glGenBuffers(1, &vertex_buffer_id);
	glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_id);
	glBufferData(GL_ARRAY_BUFFER, sizeof(cube_vertex_buffer), cube_vertex_buffer, GL_STATIC_DRAW);
	
	glfwSetInputMode (window, GLFW_STICKY_KEYS, GL_TRUE);
	
	bool looping = true;
	
	
	uint ticks = 0;
	
	
	static const GLfloat cube_color_buffer[] = 
	{
		0.583f,  0.771f,  0.014f,
		0.609f,  0.115f,  0.436f,
		0.327f,  0.483f,  0.844f,
		0.822f,  0.569f,  0.201f,
		0.435f,  0.602f,  0.223f,
		0.310f,  0.747f,  0.185f,
		0.597f,  0.770f,  0.761f,
		0.559f,  0.436f,  0.730f,
		0.359f,  0.583f,  0.152f,
		0.483f,  0.596f,  0.789f,
		0.559f,  0.861f,  0.639f,
		0.195f,  0.548f,  0.859f,
		0.014f,  0.184f,  0.576f,
		0.771f,  0.328f,  0.970f,
		0.406f,  0.615f,  0.116f,
		0.676f,  0.977f,  0.133f,
		0.971f,  0.572f,  0.833f,
		0.140f,  0.616f,  0.489f,
		0.997f,  0.513f,  0.064f,
		0.945f,  0.719f,  0.592f,
		0.543f,  0.021f,  0.978f,
		0.279f,  0.317f,  0.505f,
		0.167f,  0.620f,  0.077f,
		0.347f,  0.857f,  0.137f,
		0.055f,  0.953f,  0.042f,
		0.714f,  0.505f,  0.345f,
		0.783f,  0.290f,  0.734f,
		0.722f,  0.645f,  0.174f,
		0.302f,  0.455f,  0.848f,
		0.225f,  0.587f,  0.040f,
		0.517f,  0.713f,  0.338f,
		0.053f,  0.959f,  0.120f,
		0.393f,  0.621f,  0.362f,
		0.673f,  0.211f,  0.457f,
		0.820f,  0.883f,  0.371f,
		0.982f,  0.099f,  0.879f
	};
	
	GLuint color_buffer_id;
	glGenBuffers (1, &color_buffer_id);
	glBindBuffer (GL_ARRAY_BUFFER, color_buffer_id);
	glBufferData (GL_ARRAY_BUFFER, sizeof (cube_color_buffer), cube_color_buffer, GL_STATIC_DRAW);
	
	glEnable (GL_DEPTH_TEST);
	glDepthFunc (GL_LESS);
	
	
	BMP::Load ((path + "/src/textures/bricks.bmp").c_str());
	
	
	while (looping)
	{
		ticks++;
		glfwPollEvents ();
		
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		// Upload the vertex buffer
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_id);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
		
		
		// Upload the cube colors
		
		glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, color_buffer_id);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
		
		
		
		// MVP
		
		
		mat4 projection = perspective(radians(60.0f), 16.0f / 9.0f, 0.1f, 100.0f);
		mat4 view = lookAt
		(
			vec3 (4, 3, 3), // Camera location
			vec3 (0, 0, 0), // Direction? look at the origin
			vec3 (0, 1, 0) // Rotation? Look up
		);
		mat4 model = mat4(1.0f);
		
		mat4 mvp = projection * view * model;
		
		
		
		// MVP
		
		
		shader->Enable (mvp);
		glDrawArrays(GL_TRIANGLES, 0, 12*3);
		
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
	
	glDeleteBuffers (1, &vertex_buffer_id);
	glDeleteVertexArrays (1, &vertex_array_id);
	
	glfwTerminate ();
	
	return 0;
}