// Copyright 2017 Daniel Jones. All Rights Reserved.

/* Object.h
	Description:
		Base Class for everything in the engine 
*/

#pragma once

class Object;

#include "Memory/Master.h"

class ObjectMemory
{
public:
	Master* master;
};

class Object
{
public:
	virtual ~Object ();
	ObjectMemory object_memory;
};
