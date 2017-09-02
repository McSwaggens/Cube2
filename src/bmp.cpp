#include "bmp.h"

#include <stdio.h>

Texture* BMP::Load (const char* image_location)
{
	FILE* file = fopen (image_location, "r");
	
	if (!file)
	{
		printf ("Invalid file location or file was unable to be read due to user permissions.\n");
		return nullptr;
	}
	
	unsigned char header[54];
	
	if (fread (header, 1, 54, file) != 54)
	{
		printf ("BMP file header format is wrong\n");
		
		return nullptr;
	}
	
	if (header[0] != 'B' || header[1] != 'M')
	{
		printf ("BMP file header format is wrong\n");
		
		return nullptr;
	}
	
	int data_pos = *(int*)&(header[0x0A]);
	int image_size = *(int*)&(header[0x22]);
	int width = *(int*)&(header[0x12]);
	int height = *(int*)&(header[0x16]);
	
	if (data_pos == 0)
	{
		data_pos = 54;
		printf ("Guessed data position\n");
	}
	
	if (image_size == 0)
	{
		image_size = width * height * 3;
		
		printf ("Guessed image size position\n");
	}
	
	
	unsigned char* data = new unsigned char [image_size];
	fread (data, 1, image_size, file);
	fclose (file);
	
	Texture* texture = new Texture;
	
	glGenTextures (1, &texture->texture_id);
	glBindTexture (GL_TEXTURE_2D, texture->texture_id);
	glTexImage2D (GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	
	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	
	return texture;
}