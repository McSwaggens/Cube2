#include "Node.h"

#include <stdio.h>

const Node* null_node = new Node (nullptr);

Node::Node (Master* master)
{
	this->master = master;
}

Node::~Node ()
{
	printf ("~~~ Node destructor!!!!\n");
}

void Node::Increase ()
{
	count++;
	printf ("Increase, count = %i\n", count);
}

void Node::Decrease ()
{
	count--;
	
	printf ("Decrease, count = %i\n", count);
	
	if (count == 0)
	{
		printf ("Decrease, Destroying object\n", count);
		
		
		if (master)
		{
			master->node = 0x0;
			master->Wipe ();
			master->MarkForDelete ();
		}
		
		delete this;
	}
}