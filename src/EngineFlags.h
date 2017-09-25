// Copyright 2017 Daniel Jones. All Rights Reserved.

/* EngineType.h
	Description:
		Engine type enum
*/

#pragma once

#define FLAG 1 << 

enum EngineFlag : unsigned int
{
	INITIALIZED			= FLAG 0,
	ENTITY				= FLAG 1,
	ENGINE_ENTITY		= FLAG 2,
	RENDERER			= FLAG 3,
};

#undef FLAG