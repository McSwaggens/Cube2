#include "Master.h"

#include "../Engine.h"

#include <stdio.h>

Master::Master (Object* object)
{
	this->object = object;
	
	node = new Node (this);
}

Master::~Master ()
{
	printf ("~~~ Destructor!\n");
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
	
	printf ("Wipe!\n");
}


void Master::MarkForDelete ()
{
	engine->DestroyObject (this);
}