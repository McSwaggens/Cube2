// Copyright 2017 Daniel Jones. All Rights Reserved.

/* EngineEntity.h
	Description:
		Engine EngineEntity
*/

#pragma once

#include "Entity.h"

//?
//? ─── ENGINEENTITY ───────────────────────────────────────────────────────────────
//?

class EngineEntity : public Entity
{
public:
	EngineEntity ();
	~EngineEntity ();
	
	virtual void EngineStart () { };
	virtual void OnEngineShutdown () { };
	virtual void EnginePreUpdate () { };
	virtual void EnginePostUpdate () { };
	virtual void EngineRender () { };
};


//? ────────────────────────────────────────────────────────────────────────────────
