// Copyright 2017 Daniel Jones. All Rights Reserved.

/* Vector.h
	Description:
		Vector Class
*/

#pragma once

#include <glm/glm.hpp>

class Vector;

#include "Math.h"

//?
//? ─── GLOBAL VECTORS ─────────────────────────────────────────────────────────────
//?

extern const Vector vzero;
extern const Vector vone;
extern const Vector vup;
extern const Vector vdown;
extern const Vector vleft;
extern const Vector vright;

class Vector
{
public:
	
	float x;
	float y;
	
	//?
	//? ─── CONSTRUCTORS ───────────────────────────────────────────────────────────────
	//?
	
	Vector ();
	Vector (float x);
	Vector (float x, float y);
	
	//?
	//? ─── CONVERTING TO GLM DATA TYPES ───────────────────────────────────────────────
	//?
	
	glm::vec2 ToGLM ();
	glm::vec3 ToGLM3 ();
	
	//?
	//? ─── FUNCTIONS ──────────────────────────────────────────────────────────────────
	//?
	
	Vector Move (float distance, float deg);
	Vector Move (Vector v);
	
	float GetMagnitude ();
	float Distance (Vector v);
	Vector Normalized ();
	
	//?
	//? ─── OPERATORS ──────────────────────────────────────────────────────────────────
	//?

	
		//?
		//? ─── COMPARISON OPERATORS ───────────────────────────────────────────────────────
		//?
		
		friend bool operator == (const Vector& lhs, const Vector& rhs);
		friend bool operator != (const Vector& lhs, const Vector& rhs);
		friend bool operator <  (const Vector& lhs, const Vector& rhs);
		friend bool operator >  (const Vector& lhs, const Vector& rhs);
		friend bool operator <= (const Vector& lhs, const Vector& rhs);
		friend bool operator >= (const Vector& lhs, const Vector& rhs);
	
		//?
		//? ─── FLOAT ──────────────────────────────────────────────────────────────────────
		//?

	
		friend bool operator == (const Vector& lhs, const float& rhs);
		friend bool operator != (const Vector& lhs, const float& rhs);
		friend bool operator <  (const Vector& lhs, const float& rhs);
		friend bool operator >  (const Vector& lhs, const float& rhs);
		friend bool operator <= (const Vector& lhs, const float& rhs);
		friend bool operator >= (const Vector& lhs, const float& rhs);
		
		friend bool operator == (const float& lhs, const Vector& rhs);
		friend bool operator != (const float& lhs, const Vector& rhs);
		friend bool operator <  (const float& lhs, const Vector& rhs);
		friend bool operator >  (const float& lhs, const Vector& rhs);
		friend bool operator <= (const float& lhs, const Vector& rhs);
		friend bool operator >= (const float& lhs, const Vector& rhs);
	
		//?
		//? ─── ASSIGNMENT OPERATORS ───────────────────────────────────────────────────────
		//?
		
		Vector& operator += (const Vector& rhs);
		Vector& operator -= (const Vector& rhs);
		Vector& operator *= (const Vector& rhs);
		Vector& operator /= (const Vector& rhs);
		
		//?
		//? ─── FLOAT ───────────────────────────────────────────────────────
		//?
		
		Vector& operator += (const float& rhs);
		Vector& operator -= (const float& rhs);
		Vector& operator *= (const float& rhs);
		Vector& operator /= (const float& rhs);
		
		//?
		//? ─── ARITHMETIC ──────────────────────────────────────────────────
		//?
		
		friend Vector operator + (const Vector& lhs, const Vector& rhs);
		friend Vector operator - (const Vector& lhs, const Vector& rhs);
		friend Vector operator * (const Vector& lhs, const Vector& rhs);
		friend Vector operator / (const Vector& lhs, const Vector& rhs);
		friend Vector operator % (const Vector& lhs, const Vector& rhs);
		
		//?
		//? ─── FLOAT ───────────────────────────────────────────────────────
		//?
		
		friend Vector operator + (const Vector& lhs, const float& rhs);
		friend Vector operator - (const Vector& lhs, const float& rhs);
		friend Vector operator * (const Vector& lhs, const float& rhs);
		friend Vector operator / (const Vector& lhs, const float& rhs);
		friend Vector operator % (const Vector& lhs, const float& rhs);
		
		
		
	//? ────────────────────────────────────────────────────────────────────────────────

};
