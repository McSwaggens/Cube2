// Copyright 2017 Daniel Jones. All Rights Reserved.

/* Engine.h
	Description:
		Main engine
*/

#pragma once

#include <vector>
#include <stdio.h>

#include "Game.h"
#include "Entity.h"
#include "EngineEntity.h"
#include "Renderer.h"
#include "SafeVector.h"
#include "Memory/Master.h"
#include "Memory/Handle.h"

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
	Handle<T> CreateEntity ()
	{
		Master* master = new Master(new T());
		RegisterEntity (master);
		return Handle<T> (master->node);
	}
	
	template<typename T>
	Handle<T> CreateEngineEntity ()
	{
		T* t = new T();
		Master* master = new Master(t);
		RegisterEngineEntity (master);
		return Handle<T> (master->node);
	}
	
	void InitializeSelfReference (Master* master);
	
	void RegisterEntity (Master* entity);
	void RegisterEngineEntity (Master* entity);
	// void Register (Master<Renderer> renderer);
	
	
	void DestroyObject (Master* master);
	
	void DestroyEntity (Master* entity);
	void DestroyEngineEntity (Master* engine_entity);
	// void Destroy (Master<Renderer> renderer);
	
private:
	
	SafeVector<Master*> entities;
	SafeVector<Master*> engine_entities;
	SafeVector<Master*> renderers;
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
