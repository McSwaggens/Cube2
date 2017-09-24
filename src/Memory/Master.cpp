#include "Master.h"

#include <stdio.h>

Master::Master (Object* object)
{
	this->object = object;
	
	node = new Node (this);
}

Master::~Master ()
{
	node->master = nullptr;
	delete object;
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
		
		node->master = nullptr;
		
		delete object;
	}
}
