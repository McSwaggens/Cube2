#pragma once

#include "Shader.h"
#include <string>


namespace ShaderForge
{
	Shader* CreateShader (std::string shader_path);
	bool PreCompile (std::string source, std::string& vertex_shader, std::string& fragment_shader);
}