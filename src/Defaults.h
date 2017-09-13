// Copyright 2017 Daniel Jones. All Rights Reserved.

/* Defaults.h
	Description:
		Default materials
*/

#pragma once

#include "Material.h"
#include "Shader.h"


void InitDefaults ();

extern Shader* blend_shader;
extern Shader* color_shader;
extern Shader* texture_shader;

//?
//? ─── BLEND MATERIAL ─────────────────────────────────────────────────────────────
//?

MATERIAL(Blend)
	M_TEXTURE(tex)
	M_TEXTURE(tex2)
M_END ();

extern BlendMaterial* blend_material;


//?
//? ─── TEXTURE MATERIAL ───────────────────────────────────────────────────────────
//?


MATERIAL(Texture)
M_TEXTURE(tex)
M_END ();

extern TextureMaterial* texture_material;


//?
//? ─── COLOR MATERIAL ─────────────────────────────────────────────────────────────
//?


MATERIAL(Color)
	M_COLOR(in_color)
M_END ();


extern ColorMaterial* error_material;
extern ColorMaterial* color_material;


//? ────────────────────────────────────────────────────────────────────────────────
