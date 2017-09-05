#include "Texture.h"

#include <stdio.h>

Texture::Texture ()
{
}

Texture::Texture (const char* image_location)
{
	GLuint id = SOIL_load_OGL_texture (image_location, SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y);
	
	if (!id)
	{
		printf ("Error while loading texture \"%s\",\n%s\n", image_location, SOIL_last_result());
		return;
	}
	
	this->texture_id = id;
}