#include "Engine.h"
#include "Time.h"
#include <stdio.h>
#include "OpenGL.h"
#include "WorldObject.h"
#include "Window.h"
#include "Mouse.h"
#include "Defaults.h"
#include "Material.h"
#include <string>

using namespace Window;

//?
//? ─── GLOBAL VARIABLES ───────────────────────────────────────────────────────────
//?

Engine* engine = new Engine ();
Game* game;

//?
//? ─── CONSTRUCTORS ───────────────────────────────────────────────────────────────
//?

Engine::Engine ()
{
}

//?
//? ─── ENGINE ─────────────────────────────────────────────────────────────────────
//?

void Engine::Start ()
{
	if (!InitOpenGL ())
	{
		
		printf ("Aborting Engine Start...\n");
		return;
	}
	
	InitDefaults ();
	
	game = new Game ();
	
	running = true;
	
	//WorldObject wo;
	
	Loop ();
	
	ClearOpenGL ();
	ClearMemory ();
}

//?
//? ─── OPENGL ─────────────────────────────────────────────────────────────────────
//?

std::string GetWorkingDirectory ();

void FrameBufferSizeCallback (GLFWwindow* _window, int _width, int _height)
{
	glViewport (0, 0, _width, _height);
	Window::resolution.x = _width;
	Window::resolution.y = _height;
}

void KeyCallback (GLFWwindow* window, int key, int scancode, int action, int mods)
{
	
}

bool Engine::InitOpenGL ()
{
	if (!glfwInit())
	{
		printf ("%i, Could not initialize glfw\n", stderr);
		return false;
	}
	
	glfwWindowHint (GLFW_SAMPLES, 4);
	glfwWindowHint (GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint (GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint (GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint (GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	
	window = glfwCreateWindow (1920, 1080, "Cube2", NULL, NULL);
	
	if (window == NULL)
	{
		
		printf ("%i, Could not create GLFW window\n", stderr);
		
		glfwTerminate ();
		
		return false;
	}
	
	
	
	glfwMakeContextCurrent (window);
	
	
	glewExperimental = true;
	
	if (glewInit () != GLEW_OK)
	{
		printf ("%i, Could not initialize glew\n", stderr);
		
		return false;
	}
	
	std::string path = GetWorkingDirectory ();
	
	bool looping = true;
	
	glfwSetFramebufferSizeCallback (window, FrameBufferSizeCallback);
	glfwSetKeyCallback (window, KeyCallback);
	
	Mouse::Initialize();
	
	
	
	
	
	
	return true;
}

void Engine::ClearOpenGL ()
{
	glfwTerminate ();
}


//?
//? ─── GAME LOOP ──────────────────────────────────────────────────────────────────
//?

void Engine::Loop ()
{
	while (running)
	{
		Update ();
		Render();
	}
}

void Engine::Update ()
{
	static std::vector<Entity*> new_entities;
	
	Time::Update ();
	
	if (new_entities.size() > 0)
	{
		for (int i = 0; i < new_entities.size(); i++)
		{
			Entity* entity = new_entities[i];
			
			entity->Start ();
		}
		
		new_entities.clear ();
	}
	
	std::vector<EngineEntity*>* engine_entities = &this->engine_entities.data;
	std::vector<Entity*>* entities = &this->entities.data;
	
	
	for (int i = 0; i < engine_entities->size(); i++)
	{
		EngineEntity* engine_entity = engine_entities->at(i);
		engine_entity->EnginePreUpdate ();
	}
	
	
	for (int i = 0; i < entities->size(); i++)
	{
		Entity* entity = entities->at(i);
		entity->Update ();
	}
	
	
	for (int i = 0; i < engine_entities->size(); i++)
	{
		EngineEntity* engine_entity = engine_entities->at(i);
		engine_entity->EnginePostUpdate ();
	}
	
	
	std::vector<Entity*> _new_entities = this->entities.Sort ();
	new_entities.insert (new_entities.end(), _new_entities.begin(), _new_entities.end());
	
	static float last_time = 0;
	static int frames = 0;
	frames++;
	
	
	if (Time::time - last_time >= 1.0f)
	{
		
		printf ("FPS: %i\n", frames);
		
		last_time = Time::time;
		frames = 0;
	}
	
}

void Engine::Render ()
{
	//TODO: Render scene
}

//?
//? ─── EVENT HANDLER ──────────────────────────────────────────────────────────────
//?

void Engine::HandleEvents ()
{
	//TODO: Handle events
}

//?
//? ─── REGISTERS ──────────────────────────────────────────────────────────────────
//?

void Engine::Register (Entity* entity)
{
	this->entities.Add (entity);
}

void Engine::Register (EngineEntity* entity)
{
	this->engine_entities.Add (entity);
}

//?
//? ─── MISC ───────────────────────────────────────────────────────────────────────
//?


bool Engine::IsRunning ()
{
	return this->running;
}

void Engine::Shutdown ()
{
	this->running = false;
}

//?
//? ─── MEMORY ─────────────────────────────────────────────────────────────────────
//?

void Engine::ClearMemory ()
{
	//TODO: Handle clear memory
}

//? ────────────────────────────────────────────────────────────────────────────────
