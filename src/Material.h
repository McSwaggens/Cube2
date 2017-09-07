// Copyright 2017 Daniel Jones. All Rights Reserved.

/* Material.h
	Description:
		Acts as an instance of a shader with different variables and textures.
*/

#pragma once

#include <vector>
#include <string>

#include "Shader.h"
#include "Texture.h"
#include "OpenGL.h"
#include "Vector.h"

template<typename T> 
class Cell;

//?
//? ─── MATERIAL CONSTRUCTOR ───────────────────────────────────────────────────────
//?

#define MATERIAL(c)			class c##Material : public Material { public: c##Material(Shader* shader) : Material (shader) {}
#define M_VECTOR(n)				Cell<Vector> n = Cell<Vector>(#n, (Material*)this);
#define M_TEXTURE(n)			Cell<Texture*> n = Cell<Texture*>(#n, (Material*)this);
#define M_FLOAT(n)				Cell<float> n = Cell<float>(#n, (Material*)this);
#define M_END()				}
#define M_END_INIT(n, s)	} n (s); n.Init ();

//?
//? ─── MATERIAL ───────────────────────────────────────────────────────────────────
//?

class Material
{
public:
	virtual void Enable (glm::mat4 mvp);
	virtual void Disable ();
	
	Material (Shader* shader);
	
	void Init ();
	void InitVariable (Cell<Vector>* vector_cell);
	void InitVariable (Cell<Texture*>* texture_cell);
	void InitVariable (Cell<float>* f_cell);
protected:
	
	Shader* shader;
	std::vector<Cell<Texture*>*> texture_cells;
	std::vector<Cell<Vector>*> vector_cells;
	std::vector<Cell<float>*> float_cells;
	GLint time_id;
};

//?
//? ─── CELL ───────────────────────────────────────────────────────────────────────
//?

template<typename T> 
class Cell
{
public:
	std::string variable_name;
	GLint id;
	T data;
	
	//? The constructor has to be inside of the headerfile, otherwise we're going to get errors :(
	Cell (std::string variable_name, Material* material)
	{
		this->variable_name = variable_name;
		material->InitVariable (this);
	}
};


//? ────────────────────────────────────────────────────────────────────────────────
