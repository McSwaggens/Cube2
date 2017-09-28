#include "Master.h"

#include "../Engine.h"
#include "../Logger.h"

Master::Master (Object* object)
{
	this->object = object;
	
	node = new Node (this);
}

Master::~Master ()
{
	Log (DEBUG, "~~~ Destructor!");
	Wipe ();
}



void Master::Wipe ()
{
	if (object)
	{
		delete object;
		object = nullptr;
	}
	
	if (node)
	{
		node->master = nullptr;
		node = nullptr;
	}
	
	Log (DEBUG, "Wipe!");
}


void Master::MarkForDelete ()
{
	engine->DestroyObject (this);
}