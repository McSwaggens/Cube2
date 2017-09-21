#include <unistd.h>

#include "Defaults.h"
#include "ShaderCompiler.h"


Shader* blend_shader;
Shader* color_shader;
Shader* texture_shader;

BlendMaterial* blend_material;
TextureMaterial* texture_material;
ColorMaterial* error_material;
ColorMaterial* color_material;


std::string GetWorkingDirectory ()
{
	char path[FILENAME_MAX];
	getcwd(path, FILENAME_MAX);
	return std::string(path);
}

void InitDefaults ()
{
	
	std::string path = GetWorkingDirectory ();
	
	//?
	//? ─── INIT SHADERS ───────────────────────────────────────────────────────────────
	//?

	
	blend_shader = ShaderForge::CreateShader (path + "/src/shaders/Blend.glsl");
	texture_shader = ShaderForge::CreateShader (path + "/src/shaders/Textured.glsl");
	color_shader = ShaderForge::CreateShader (path + "/src/shaders/Color.glsl");
	
	
	//?
	//? ─── BLEND MATERIAL ─────────────────────────────────────────────────────────────
	//?

	
	blend_material = new BlendMaterial (blend_shader);
	blend_material->Init ();
	
	
	Texture* texture_a = new Texture ((path + "/src/textures/tux.png").c_str());
	Texture* texture_b = new Texture ((path + "/src/textures/bricks.bmp").c_str());
	
	blend_material->tex.data = texture_a;
	blend_material->tex2.data = texture_b;
	
	//?
	//? ─── TEXTURE MATERIAL ───────────────────────────────────────────────────────────
	//?

	
	texture_material = new TextureMaterial (texture_shader);
	texture_material->Init ();
	
	
	//?
	//? ─── COLOR MATERIAL ─────────────────────────────────────────────────────────────
	//?
	
	
	color_material = new ColorMaterial (color_shader);
	color_material->Init ();
	
	
	//? ────────────────────────────────────────────────────────────────────────────────

}

