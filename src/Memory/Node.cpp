#include "Node.h"

#include "../Logger.h"

const Node* null_node = new Node (nullptr);

Node::Node (Master* master)
{
	this->master = master;
}

Node::~Node ()
{
	Log (DEBUG, "~~~ Node destructor!!!!");
}

void Node::Increase ()
{
	count++;
	Log (DEBUG, "Increase, count = ", count);
}

void Node::Decrease ()
{
	count--;
	
	Log (DEBUG, "Decrease, count = ", count);
	
	if (count == 0)
	{
		Log (DEBUG, "Decrease, Destroying object, count = ", count);
		
		if (master)
		{
			master->node = 0x0;
			master->Wipe ();
			master->MarkForDelete ();
		}
		
		delete this;
	}
}