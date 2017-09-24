// Copyright 2017 Daniel Jones. All Rights Reserved.

/* Entity.h
	Description:
		Entity Class
*/

#pragma once

#include "Object.h"

//?
//? ─── ENTITY ─────────────────────────────────────────────────────────────────────
//?


class Entity : public Object
{
public:
	Entity ();
	virtual void Start () { }
	virtual void Update () { };
};

//? ────────────────────────────────────────────────────────────────────────────────
