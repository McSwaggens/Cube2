#include "Engine.h"

#include "Time.h"
#include "OpenGL.h"
#include "WorldObject.h"
#include "Window.h"
#include "Mouse.h"
#include "Defaults.h"
#include "Material.h"
#include "Graphics.h"

#include <string>
#include <stdio.h>

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
	
	Graphics::InitGraphics ();
	InitDefaults ();
	
	Handle<Game> _game = CreateEngineEntity<Game> ();
	
	
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

Texture* texture_a;
Texture* texture_b;


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
	
	GLuint VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	
	glEnable (GL_BLEND);
	glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	
	
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
	static std::vector<Master*> new_entities;
	
	HandleEvents ();
	
	Time::Update ();
	Mouse::Update ();
	
	if (new_entities.size() > 0)
	{
		for (int i = 0; i < new_entities.size(); i++)
		{
			Entity* entity = (Entity*)new_entities[i]->object;
			
			entity->Start ();
		}
		
		new_entities.clear ();
	}
	
	for (int i = 0; i < engine_entities.data.size(); i++)
	{
		EngineEntity* engine_entity = (EngineEntity*)engine_entities.data[i]->object;
		engine_entity->EnginePreUpdate ();
	}
	
	
	for (int i = 0; i < entities.data.size(); i++)
	{
		Entity* entity = (Entity*)entities.data[i]->object;
		entity->Update ();
	}
	
	
	for (int i = 0; i < engine_entities.data.size(); i++)
	{
		EngineEntity* engine_entity = (EngineEntity*)engine_entities.data[i]->object;
		engine_entity->EnginePostUpdate ();
	}
	
	
	// Collect all removed objects before they're sorted out
	std::vector<Master*> removed_objects;
	removed_objects.insert (removed_objects.end(), entities.remove_stack.begin(), entities.remove_stack.end());
	removed_objects.insert (removed_objects.end(), engine_entities.remove_stack.begin(), engine_entities.remove_stack.end());
	
	// Removed all duplicates
	std::sort (removed_objects.begin(), removed_objects.end());
	removed_objects.erase (std::unique(removed_objects.begin (), removed_objects.end()), removed_objects.end());
	
	// Sort the SafeVectors and fill the static "new_entities" vector above
	std::vector<Master*> _new_entities = this->entities.Sort();
	new_entities.insert (new_entities.end(), _new_entities.begin(), _new_entities.end());
	std::vector<Master*> _new_engine_entities = this->engine_entities.Sort();
	
	// Delete the cached masters
	for (int i = 0; i < removed_objects.size (); i++)
	{
		Master* master = removed_objects[i];
		delete master;
	}
	
	// this->renderers.Sort ();
	
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

Camera* camera = new Camera ();

void Engine::Render ()
{
	glClearColor(0.05f, 0.05f, 0.05f, 1.0f);
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	camera->AddZoom(-Mouse::scroll.y * 2);
	camera->UpdatePVMatrix ();
	
	Vector mouse_pos = Mouse::GetWorldPosition (camera);
	
	// std::vector<Master<Renderer>>* renderers = &this->renderers.data;
	
	// for (int i = 0; i < renderers->size(); i++)
	// {
	// 	Renderer* renderer = renderers->at(i).value;
		
	// 	renderer->Render (camera);
	// }
	
	
	Graphics::DrawLine (camera, vleft, vright, white);
	Graphics::DrawLine (camera, vup, vdown, red);
	
	
	glfwSwapBuffers (window);
}

//?
//? ─── EVENT HANDLER ──────────────────────────────────────────────────────────────
//?

void Engine::HandleEvents ()
{
	glfwPollEvents ();
	
	bool window_closed = glfwWindowShouldClose (window);
	
	if (window_closed || glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		Shutdown ();
	}
	
}

//?
//? ─── REGISTERS ──────────────────────────────────────────────────────────────────
//?

// template<typename T, typename = std::enable_if<std::is_base_of<Entity, T>::value>>
// T** Engine::Create ()
// {
// 	T* t = new T();
	
// 	this->Register ((Entity*)t);
	
// 	return &t;
// }

void Engine::InitializeSelfReference (Master* master)
{
	// Set a reference to itself
	master->object->object_memory.master = master;
}

void Engine::RegisterEntity (Master* entity)
{
	InitializeSelfReference (entity);
	this->entities.Add (entity);
}

void Engine::RegisterEngineEntity (Master* entity)
{
	InitializeSelfReference (entity);
	this->entities.Add (entity);
	this->engine_entities.Add (entity);
}

void Engine::DestroyObject (Master* master)
{
	entities.Remove (master);
	engine_entities.Remove (master);
	// renderers.Remove (master);
}

void Engine::DestroyEntity (Master* entity)
{
	entities.Remove (entity);
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
