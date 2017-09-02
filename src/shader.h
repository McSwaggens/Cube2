#pragma once

#include "opengl.h"

class Shader
{
public:
	Shader (GLuint _program_id);
	
	void Dispose ();
	
	void Enable (mat4 mvp); // Enable the shader
	void Disable (); // Disable the shader
private:
	GLuint program_id;
	GLuint matrix_id;
};