#include "Texture.h"

#include "Logger.h"

Texture::Texture ()
{
}

void InvertTextureY (unsigned char* image_data, int width, int height, int channels)
{
	int i, j;
	for( j = 0; j*2 < height; ++j )
	{
		int index1 = j * width * channels;
		int index2 = (height - 1 - j) * width * channels;
		for(i = width * channels; i > 0; --i)
		{
			GLubyte temp = image_data[index1];
			image_data[index1] = image_data[index2];
			image_data[index2] = temp;
			++index1;
			++index2;
		}
	}
}

Texture::Texture (const char* image_location)
{
	
	glGenTextures (1, &texture_id);
	
	if (!texture_id)
	{
		Log (ERROR, "Unable to generate a gpu texture id, stderr = ", stderr);
		return;
	}
	
	glBindTexture (GL_TEXTURE_2D, texture_id);
	
	int width, height, channels;
	unsigned char* image_data = SOIL_load_image (image_location, &width, &height, &channels, SOIL_LOAD_RGBA);
	
	if (!image_data)
	{
		Log (ERROR, "Unable to load image using libSOIL, SOIL_last_result = ", SOIL_last_result());
		
		return;
	}
	
	InvertTextureY (image_data, width, height, channels);
	
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image_data);
	
	
	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	
	glGenerateMipmap(GL_TEXTURE_2D);
	
	SOIL_free_image_data (image_data);
	
}

Texture::~Texture ()
{
}