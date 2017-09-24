// Copyright 2017 Daniel Jones. All Rights Reserved.

/* Game.h
	Description:
		Main game code
*/

#pragma once


//?
//? ─── FORWARD DECLARATION ────────────────────────────────────────────────────────
//?

class Game;

#include "Engine.h"
#include "EngineEntity.h"

class Game : public EngineEntity
{
public:
	
	Game ();
	
	virtual void EnginePreUpdate ();
	virtual void Start ();
	virtual void Update ();
};