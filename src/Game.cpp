#include "Game.h"

#include <stdio.h>
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
	Destroy ();
}
