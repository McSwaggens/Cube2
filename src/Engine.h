// Copyright 2017 Daniel Jones. All Rights Reserved.

/* Engine.h
	Description:
		Main engine
*/

#pragma once

#include <vector>

#include "Game.h"
#include "Entity.h"
#include "EngineEntity.h"
#include "SafeVector.h"

//?
//? ─── FORWARD DECLARATION ────────────────────────────────────────────────────────
//?

class Engine;

#include "FDecl.h"

//?
//? ─── ENGINE ─────────────────────────────────────────────────────────────────────
//?


class Engine
{
public:
	
	Engine ();
	
	void Start ();
	
	bool IsRunning ();
	void Shutdown ();
	
	void Register (Entity* entity);
	void Register (EngineEntity* entity);
	
private:
	
	SafeVector<Entity*> entities;
	SafeVector<EngineEntity*> engine_entities;
	bool running;
	
	void Loop ();
	void Update ();
	void Render ();
	void HandleEvents ();
	bool InitOpenGL ();
	
	void ClearOpenGL ();
	void ClearMemory ();
	
};


//? ────────────────────────────────────────────────────────────────────────────────
