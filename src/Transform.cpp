#include "Transform.h"

//?
//? ─── CONSTRUCTORS ───────────────────────────────────────────────────────────────
//?

Transform::Transform ()
{
	this->position = Vector (0, 0);
	this->scale = Vector (1, 1);
	this->rotation = 0.0f;
}


Transform::Transform (Vector position, float rotation, Vector scale)
{
	this->position = position;
	this->scale = scale;
	this->rotation = rotation;
}


//?
//? ─── FUNCTIONS ──────────────────────────────────────────────────────────────────
//?


Vector Transform::LocalMove (float distance)
{
	return this->position.Move(distance, rotation);
}


//? ────────────────────────────────────────────────────────────────────────────────
