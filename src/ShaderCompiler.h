// Copyright 2017 Daniel Jones. All Rights Reserved.

/* ShaderCompiler.h
	Description:
		Compiles the raw shader file (glsl)
		Also does some magic vert and frag separation so we can have a vertex and a fragment shader in the same file.
*/



#pragma once

#include "Shader.h"
#include <string>


namespace ShaderForge
{
	Shader* CreateShader (std::string shader_path);
	bool PreCompile (std::string source, std::string& vertex_shader, std::string& fragment_shader);
}