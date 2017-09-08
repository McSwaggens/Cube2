#include "Vector.h"
#include "Math.h"

//?
//? ─── GLOBAL VECTORS ─────────────────────────────────────────────────────────────
//?

Vector zero (0, 0);
Vector one (1, 1);
Vector up (0, 1);
Vector down (0, -1);
Vector left (-1, 0);
Vector right (1, 0);

//?
//? ─── CONSTRUCTORS ───────────────────────────────────────────────────────────────
//?


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


//?
//? ─── FUNCTIONS ──────────────────────────────────────────────────────────────────
//?

float Vector::GetMagnitude ()
{
	return sqrt(x * x + y * y);
}

//?
//? ─── CONVERTING TO GLM DATA TYPES ───────────────────────────────────────────────
//?


glm::vec2 Vector::ToGLM ()
{
	return *(glm::vec2*)(void*)this;
}

glm::vec3 Vector::ToGLM3 ()
{
	return glm::vec3(x, y, 0.0f);
}


//?
//? ─── COMPARISON OPERATORS ───────────────────────────────────────────────────────
//?

	bool operator == (const Vector& lhs, const Vector& rhs)
	{
		return lhs.x == rhs.x && lhs.y == rhs.y;
	}

	bool operator != (const Vector& lhs, const Vector& rhs)
	{
		return lhs.x != rhs.x && lhs.y != rhs.y;
	}

	bool operator <  (const Vector& lhs, const Vector& rhs)
	{
		return lhs.x < rhs.x && lhs.y < rhs.y;
	}

	bool operator >  (const Vector& lhs, const Vector& rhs)
	{
		return lhs.x > rhs.x && lhs.y > rhs.y;
	}

	bool operator <= (const Vector& lhs, const Vector& rhs)
	{
		return lhs.x <= rhs.x && lhs.y <= rhs.y;
	}

	bool operator >= (const Vector& lhs, const Vector& rhs)
	{
		return lhs.x >= rhs.x && lhs.y >= rhs.y;
	}

	//?
	//? ─── FLOAT ──────────────────────────────────────────────────────────────────────
	//?

	bool operator == (const Vector& lhs, const float& rhs)
	{
		return lhs.x == rhs && lhs.y == rhs;
	}

	bool operator != (const Vector& lhs, const float& rhs)
	{
		return lhs.x != rhs && lhs.y != rhs;
	}

	bool operator <  (const Vector& lhs, const float& rhs)
	{
		return lhs.x < rhs && lhs.y < rhs;
	}

	bool operator >  (const Vector& lhs, const float& rhs)
	{
		return lhs.x > rhs && lhs.y > rhs;
	}

	bool operator <= (const Vector& lhs, const float& rhs)
	{
		return lhs.x <= rhs && lhs.y <= rhs;
	}

	bool operator >= (const Vector& lhs, const float& rhs)
	{
		return lhs.x >= rhs && lhs.y >= rhs;
	}
	
	
	
	
	bool operator == (const float& lhs, const Vector& rhs)
	{
		return lhs == rhs.x && lhs == rhs.y;
	}

	bool operator != (const float& lhs, const Vector& rhs)
	{
		return lhs != rhs.x && lhs != rhs.y;
	}

	bool operator <  (const float& lhs, const Vector& rhs)
	{
		return lhs < rhs.x && lhs < rhs.y;
	}

	bool operator >  (const float& lhs, const Vector& rhs)
	{
		return lhs > rhs.x && lhs > rhs.y;
	}

	bool operator <= (const float& lhs, const Vector& rhs)
	{
		return lhs <= rhs.x && lhs <= rhs.y;
	}

	bool operator >= (const float& lhs, const Vector& rhs)
	{
		return lhs >= rhs.x && lhs >= rhs.y;
	}

//?
//? ─── ASSIGNMENT OPERATORS ───────────────────────────────────────────────────────
//?
	
	Vector& Vector::operator += (const Vector& rhs)
	{
		x += rhs.x;
		y += rhs.y;
		return *this;
	}
	
	Vector& Vector::operator -= (const Vector& rhs)
	{
		x -= rhs.x;
		y -= rhs.y;
		return *this;
	}
	
	Vector& Vector::operator *= (const Vector& rhs)
	{
		x *= rhs.x;
		y *= rhs.y;
		return *this;
	}
	
	Vector& Vector::operator /= (const Vector& rhs)
	{
		x /= rhs.x;
		y /= rhs.y;
		return *this;
	}
	
	//?
	//? ─── FLOAT ──────────────────────────────────────────────────────────────────────
	//?
	
	Vector& Vector::operator += (const float& rhs)
	{
		x += rhs;
		y += rhs;
		return *this;
	}
	
	Vector& Vector::operator -= (const float& rhs)
	{
		x -= rhs;
		y -= rhs;
		return *this;
	}
	
	Vector& Vector::operator *= (const float& rhs)
	{
		x *= rhs;
		y *= rhs;
		return *this;
	}
	
	Vector& Vector::operator /= (const float& rhs)
	{
		x /= rhs;
		y /= rhs;
		return *this;
	}
	
//?
//? ─── ARITHMETIC ─────────────────────────────────────────────────────────────────
//?
	

	Vector operator + (const Vector& lhs, const Vector& rhs)
	{
		return Vector (lhs.x + rhs.x, lhs.y + rhs.y);
	}

	Vector operator - (const Vector& lhs, const Vector& rhs)
	{
		return Vector (lhs.x - rhs.x, lhs.y - rhs.y);
	}

	Vector operator * (const Vector& lhs, const Vector& rhs)
	{
		return Vector (lhs.x * rhs.x, lhs.y * rhs.y);
	}

	Vector operator / (const Vector& lhs, const Vector& rhs)
	{
		return Vector (lhs.x / rhs.x, lhs.y / rhs.y);
	}
	
	//?
	//? ─── FLOAT ──────────────────────────────────────────────────────────────────────
	//?
	
	Vector operator + (const Vector& lhs, const float& rhs)
	{
		return Vector (lhs.x + rhs, lhs.y + rhs);
	}

	Vector operator - (const Vector& lhs, const float& rhs)
	{
		return Vector (lhs.x - rhs, lhs.y - rhs);
	}

	Vector operator * (const Vector& lhs, const float& rhs)
	{
		return Vector (lhs.x * rhs, lhs.y * rhs);
	}

	Vector operator / (const Vector& lhs, const float& rhs)
	{
		return Vector (lhs.x / rhs, lhs.y / rhs);
	}
	
//? ────────────────────────────────────────────────────────────────────────────────
