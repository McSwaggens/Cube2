// Copyright 2017 Daniel Jones. All Rights Reserved.

/* WorldObject.h
	Description:
		
*/

#pragma once

#include "Entity.h"
#include "Transform.h"


class WorldObject : public Entity
{
	Transform transform;
	
	void Start ();
};