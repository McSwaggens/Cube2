#include "ShaderCompiler.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "Logger.h"


std::string LoadFile (std::string path)
{
	std::ifstream file (path);
	std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
	return content;
}


enum Stage
{
	STAGE_GLOBAL,
	STAGE_VERT,
	STAGE_FRAG
};

void ParseLines (std::vector<std::string> source, std::string& vertex_shader, std::string& fragment_shader)
{
	Stage stage = STAGE_GLOBAL;
	std::string global;
	std::string current;
	for (int i = 0; i < source.size(); i++)
	{
		std::string line = source[i];
		Stage new_st = stage;
		
		if (stage == STAGE_GLOBAL && (line == "#vert" || line == "#frag"))
		{
			global = current + "\n";
			current = global;
			// To be filled in when I need it ...
		}
		
		if (line == "#vert")
		{
			if (stage == STAGE_FRAG)
			{
				fragment_shader = current;
				current = global + "\n";
			}
			
			stage = STAGE_VERT;
		}
		else if (line == "#frag")
		{
			if (stage == STAGE_VERT)
			{
				vertex_shader = current;
				current = global + "\n";
			}
			
			stage = STAGE_FRAG;
		}
		else
		{
			current += line + "\n";
		}
	}
	
	if (stage == STAGE_VERT)
	{
		vertex_shader = current;
	}
	else if (stage == STAGE_FRAG)
	{
		fragment_shader = current;
	}
}

std::vector<std::string> SeparateLines (std::string str)
{
	std::vector<std::string> lines;
	
	std::stringstream iss (str);
	
	while (iss.good ())
	{
		std::string line;
		getline (iss, line, '\n');
		lines.push_back (line);
	}
	
	return lines;
}


bool ShaderForge::PreCompile (std::string source, std::string& vertex_shader, std::string& fragment_shader)
{
	std::vector<std::string> lines = SeparateLines (source);
	
	std::string vert;
	std::string frag;
	
	ParseLines (lines, vert, frag);
	
	vertex_shader = vert;
	fragment_shader = frag;
}

GLuint CompileShaderSource (std::string source, GLuint shader_type)
{
	GLuint shader_id = glCreateShader (shader_type);
	
	GLint result = GL_FALSE;
	int log_length;
	
	const char* vert_src_ptr = source.c_str();
	
	// Load the source code to be compiled
	glShaderSource (shader_id, 1, &vert_src_ptr, NULL);
	
	// Compile the shader
	glCompileShader (shader_id);
	
	
	glGetShaderiv (shader_id, GL_COMPILE_STATUS, &result);
	glGetShaderiv (shader_id, GL_INFO_LOG_LENGTH, &log_length);
	
	if (log_length > 0)
	{
		std::vector<char> error_message (log_length + 1);
		glGetShaderInfoLog (shader_id, log_length, NULL, &error_message[0]);
		
		printf ("[SHADER COMPILE ERROR]:\n%s\n", &error_message[0]);
	}
	
	return shader_id;
}

Shader* ShaderForge::CreateShader (std::string path)
{
	std::string source (LoadFile(path));
	
	std::string vert;
	std::string frag;
	
	PreCompile (source, vert, frag);
	
	Shader* shader = nullptr;
	
	GLuint vertex_shader_id = CompileShaderSource (vert, GL_VERTEX_SHADER);
	GLuint frag_shader_id = CompileShaderSource (frag, GL_FRAGMENT_SHADER);
	
	GLuint program_id = glCreateProgram ();
	glAttachShader (program_id, vertex_shader_id);
	glAttachShader (program_id, frag_shader_id);
	glLinkProgram (program_id);
	
	
	
	GLint result = GL_FALSE;
	int log_length;
	
	
	glGetProgramiv (program_id, GL_LINK_STATUS, &result);
	glGetProgramiv (program_id, GL_INFO_LOG_LENGTH, &log_length);
	
	if (log_length > 0)
	{
		std::vector<char> error_message (log_length + 1);
		glGetProgramInfoLog (program_id, log_length, NULL, &error_message[0]);
		
		Log (ERROR, "Shader linker error, path = ", path);

		printf ("[SHADER LINK ERROR]:\n%s\n", &error_message[0]);
		
		return shader;
	}
	
	glDetachShader (program_id, vertex_shader_id);
	glDetachShader(program_id, frag_shader_id);
	
	glDeleteShader (vertex_shader_id);
	glDeleteShader (frag_shader_id);
	
	shader = new Shader (program_id);
	
	return shader;
	
}
