#include "Node.h"

const Node* null_node = new Node (nullptr);

Node::Node (Master* master)
{
	this->master = master;
}