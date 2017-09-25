#include "Game.h"

#include <stdio.h>
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
	printf ("Hello World from Game.cpp!\n");
	std::bitset<32> binary (engine_data.flags);
	
	
	printf ("flags binary: %u %s\n", engine_data.flags, binary.to_string().c_str());
	Destroy ();
}
