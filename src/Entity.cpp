#include "Entity.h"

#include "Engine.h"

Entity::Entity ()
{
	engine->Register (this);
}