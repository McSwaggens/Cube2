// Copyright 2017 Daniel Jones. All Rights Reserved.

/* Engine.h
	Description:
		Main engine
*/

#pragma once

#include <vector>
#include "Logger.h"

#include "Game.h"
#include "Entity.h"
#include "EngineEntity.h"
#include "Renderer.h"
#include "SafeVector.h"
#include "Memory/Master.h"
#include "Memory/Handle.h"
#include "Logger.h"

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
	
	template<typename T>
	Handle<T> Create ()
	{
		Master* master = new Master(new T());
		RegisterObject (master);
		return Handle<T> (master->node);
	}
	
	void InitializeSelfReference (Master* master);
	void RegisterObject (Master* entity);
	void DestroyObject (Master* master);
	
private:
	
	SafeVector<Master*> entities;
	SafeVector<Master*> engine_entities;
	SafeVector<Master*> renderers;
	
	std::vector<Master*> remove_stack;
	
	bool running;
	
	void Loop ();
	void Update ();
	void Render ();
	void HandleEvents ();
	bool InitOpenGL ();
	void CalculateRemoveStack ();
	
	void ClearOpenGL ();
	void ClearMemory ();
	
};


//? ────────────────────────────────────────────────────────────────────────────────
