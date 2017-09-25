// Copyright 2017 Daniel Jones. All Rights Reserved.

/* Object.h
	Description:
		Base Class for everything in the engine 
*/

#pragma once

class Object;

#include "Memory/Master.h"
#include "EngineFlags.h"


class EngineData
{
public:
	Master* master;
	unsigned long flags;
};

class Object
{
public:
	Object ();
	virtual ~Object ();
	EngineData engine_data;
	void Keep ();
	void Destroy ();
	
	void EnableFlag (unsigned long flag);
	void DisableFlag (unsigned long flag);
	void SwitchFlag (unsigned long flag);
	bool GetFlag (unsigned long flag);
};
