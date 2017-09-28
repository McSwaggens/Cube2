#include "Game.h"

#include "Logger.h"
#include <bitset>
#include "WorldObject.h"

Game::Game ()
{
}

void Game::Update ()
{
}

void Game::EnginePreUpdate ()
{
	
}

void Game::Start ()
{
	Log (INFO, "Hello World from Game.cpp!");
	std::bitset<32> binary (engine_data.flags);
	
	
	Log (INFO, "flags binary: ", engine_data.flags, " ", binary.to_string());
	Destroy ();
}
