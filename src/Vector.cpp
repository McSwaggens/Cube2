#include "Vector.h"


Vector::Vector ()
{
	this->x = 0;
	this->y = 0;
}

Vector::Vector (float x)
{
	this->x = x;
	this->y = x;
}

Vector::Vector (float x, float y)
{
	this->x = x;
	this->y = y;
}

glm::vec2 Vector::ToGLM ()
{
	return *(glm::vec2*)(void*)this;
}

glm::vec3 Vector::ToGLM3 ()
{
	return glm::vec3(x, y, 0.0f);
}