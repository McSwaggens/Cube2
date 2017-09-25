// Copyright 2017 Daniel Jones. All Rights Reserved.

/* Object.h
	Description:
		Base Class for everything in the engine 
*/

#pragma once

class Object;

#include "Memory/Master.h"

class EngineData
{
public:
	Master* master;
};

class Object
{
public:
	virtual ~Object ();
	EngineData engine_data;
	void Keep ();
	void Destroy ();
};
