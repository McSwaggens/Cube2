#include "Material.h"
#include "Time.h"

Material::Material (Shader* shader)
{
	this->shader = shader;
}

void Material::Init ()
{
	
	for (int i = 0; i < this->texture_cells.size(); i++)
	{
		Cell<Texture*>* tex_cell = texture_cells[i];
		tex_cell->id = glGetUniformLocation (shader->program_id, tex_cell->variable_name.c_str());
	}
	
	for (int i = 0; i < this->vector_cells.size(); i++)
	{
		Cell<Vector>* vec_cell = vector_cells[i];
		vec_cell->id = glGetUniformLocation (shader->program_id, vec_cell->variable_name.c_str());
	}
	
	for (int i = 0; i < this->float_cells.size(); i++)
	{
		Cell<float>* float_cell = float_cells[i];
		float_cell->id = glGetUniformLocation (shader->program_id, float_cell->variable_name.c_str());
	}
	
	
	//?
	//? ─── GET THE TIME UNIFORM ───────────────────────────────────────────────────────
	//?
	
	
	time_id = glGetUniformLocation (shader->program_id, "time");
}

void Material::Enable (glm::mat4 mvp)
{
	this->shader->Enable (mvp);
	
	for (int i = 0; i < this->texture_cells.size(); i++)
	{
		Cell<Texture*>* tex_cell = texture_cells[i];
		
		glActiveTexture (GL_TEXTURE0+i);
		glBindTexture (GL_TEXTURE_2D, tex_cell->data->texture_id);
		glUniform1i (tex_cell->id, i);
	}
	
	//* Check if the shader actually has a time variable
	if (time_id != -1)
	{
		glUniform1f(time_id, Time::time);
	}
}

void Material::Disable ()
{
	shader->Disable ();
}

void Material::InitVariable (Cell<Vector>* vector_cell)
{
	this->vector_cells.push_back (vector_cell);
}

void Material::InitVariable (Cell<Texture*>* texture_cell)
{
	// OpenGL can only hold 32 textures at a single time
	if (texture_cells.size() < 32)
	{
		this->texture_cells.push_back (texture_cell);
	}
}

void Material::InitVariable (Cell<float>* f_cell)
{
	this->float_cells.push_back (f_cell);
}
