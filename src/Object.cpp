#include "Object.h"

#include "Engine.h"

Object::~Object ()
{
}

void Object::Keep ()
{
	engine_data.master->Increase ();
}

void Object::Destroy ()
{
	
	engine->DestroyObject (engine_data.master);
	
	return;
	engine_data.master->Wipe ();
	engine_data.master->MarkForDelete ();
}