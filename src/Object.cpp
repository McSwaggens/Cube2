#include "Object.h"

#include "Engine.h"

//?
//? ─── CONSTRUCTORS ───────────────────────────────────────────────────────────────
//?


Object::Object ()
{
	// Initialize the flag to zero
	engine_data.flags = 0x0;
}

Object::~Object ()
{
}

//?
//? ─── MISC ───────────────────────────────────────────────────────────────────────
//?


void Object::Keep ()
{
	engine_data.master->Increase ();
}

void Object::Destroy ()
{
	engine->DestroyObject (engine_data.master);
}

//?
//? ─── FLAGS ──────────────────────────────────────────────────────────────────────
//?


void Object::EnableFlag (unsigned long flag)
{
	engine_data.flags |= flag;
}

void Object::DisableFlag (unsigned long flag)
{
	engine_data.flags &= ~flag;
}

void Object::SwitchFlag (unsigned long flag)
{
	engine_data.flags ^= flag;
}

bool Object::GetFlag (unsigned long flag)
{
	return static_cast<bool>(engine_data.flags & flag);
}

//? ────────────────────────────────────────────────────────────────────────────────
