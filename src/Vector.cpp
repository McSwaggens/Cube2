#include "Vector.h"
#include "Math.h"

//?
//? ─── GLOBAL VECTORS ─────────────────────────────────────────────────────────────
//?

const Vector vzero (0, 0);
const Vector vone (1, 1);
const Vector vup (0, 1);
const Vector vdown (0, -1);
const Vector vleft (-1, 0);
const Vector vright (1, 0);

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
	return sqrt((x * x) + (y * y));
}

float Vector::Distance (Vector v)
{
	return ((*this) - v).GetMagnitude();
}

Vector Vector::Move (float distance, float deg)
{
	return (*this) = (*this) + (Vector (-Sin((2*PI*deg)/360), Cos((2*PI*deg)/360)) * distance);
}

Vector Vector::Move (Vector v)
{
	return (*this) += v;
}

Vector Vector::Normalized ()
{
	float mag = GetMagnitude ();
	
	if (mag > 0)
	{
		return (*this) / mag;
	}
	
	return vzero;
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
