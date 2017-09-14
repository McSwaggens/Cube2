#include "EngineEntity.h"

#include "Engine.h"

EngineEntity::EngineEntity ()
{
	engine->Register (this);
}