// Copyright 2017 Daniel Jones. All Rights Reserved.

/* Master.h
	Description:
		
*/

#pragma once


class Master;

#include "../Object.h"
#include "Node.h"

class Master
{
public:
	int count = 0;
	Object* object;
	Node* node;
	Master (Object* object);
	~Master ();
	void Increase ();
	void Decrease ();
	void Wipe ();
	void MarkForDelete ();
};