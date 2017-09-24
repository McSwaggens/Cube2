#include "Object.h"

#include "Engine.h"

Object::~Object ()
{
}

void Object::Keep ()
{
	object_memory.master->Increase ();
}

void Object::Destroy ()
{
	
	engine->DestroyObject (object_memory.master);
	
	return;
	object_memory.master->Wipe ();
	object_memory.master->MarkForDelete ();
}