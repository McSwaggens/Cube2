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

void Master::Increase ()
{
	count++;
	printf ("Increase, count = %i\n", count);
}

void Master::Decrease ()
{
	count--;
	
	printf ("Decrease, count = %i\n", count);
	
	if (count == 0)
	{
		printf ("Decrease, Destroying object\n", count);
		
		Wipe ();
		MarkForDelete ();
	}
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
	}
	
	printf ("Wipe!\n");
}


void Master::MarkForDelete ()
{
	engine->DestroyObject (this);
}