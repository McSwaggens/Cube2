#include "shader.h"

Shader::Shader (GLuint _program_id)
{
	this->program_id = _program_id;
	
	glGetUniformLocation (program_id, "MVP");
}

void Shader::Dispose ()
{
	glDeleteProgram (program_id);
}

void Shader::Enable (mat4 mvp)
{
	glUseProgram (this->program_id);
	glUniformMatrix4fv (matrix_id, 1, GL_FALSE, &mvp[0][0]);
}

void Shader::Disable ()
{
	glUseProgram (0);
}