// Copyright 2017 Daniel Jones. All Rights Reserved.

/* Node.h
	Description:
		
*/

#pragma once

class Node;

extern const Node* null_node;

#include "Master.h"

//?
//? ─── NODE ───────────────────────────────────────────────────────────────────────
//?


class Node
{
public:
	Master* master;
	int count = 0;
	
	void Increase ();
	void Decrease ();
	
	Node (Master* master);
	~Node ();
};

//? ────────────────────────────────────────────────────────────────────────────────
