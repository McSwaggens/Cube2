#include "Engine.h"

#include "Time.h"
#include "OpenGL.h"
#include "WorldObject.h"
#include "Window.h"
#include "Mouse.h"
#include "Defaults.h"
#include "Material.h"
#include "Graphics.h"
#include "Util.h"
#include "ConsoleColors.h"

#include <string>

using namespace Window;

//?
//? ─── GLOBAL VARIABLES ───────────────────────────────────────────────────────────
//?

Engine* engine = new Engine ();
Handle<Game> game;

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
		Log (ERROR, "OpenGL failed to initialize, aborting engine start...");
		return;
	}
	
	Graphics::InitGraphics ();
	InitDefaults ();
	
	
	game = Create<Game> ();
	
	running = true;
	
	//WorldObject wo;
	
	Loop ();
	
	Log (INFO, "Shutting down engine");
	
	ClearOpenGL ();
	ClearMemory ();
	
	Log (INFO, "Engine shutdown successful\nBye!");
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
		Log (ERROR, "Could not initialize GLFW, ErrorCode: ", stderr);
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
		
		Log (ERROR, "Could not create GLFW window, ErrorCode: ", stderr);
		
		glfwTerminate ();
		
		return false;
	}
	
	
	
	glfwMakeContextCurrent (window);
	
	
	glewExperimental = true;
	
	if (glewInit () != GLEW_OK)
	{
		Log (ERROR, "Could not initialize GLEW, ErrorCode: ", stderr);
		
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
	
	//?
	//? ─── ENTITY START ───────────────────────────────────────────────────────────────
	//?
	
	if (new_entities.size() > 0)
	{
		for (int i = 0; i < new_entities.size(); i++)
		{
			Entity* entity = (Entity*)new_entities[i]->object;
			
			entity->Start ();
			
			// Enable the initialized flag
			entity->EnableFlag (INITIALIZED);
		}
		
		new_entities.clear ();
	}
	
	//?
	//? ─── ENGINE PRE UPDATE ──────────────────────────────────────────────────────────
	//?
	
	
	for (int i = 0; i < engine_entities.data.size(); i++)
	{
		EngineEntity* engine_entity = (EngineEntity*)engine_entities.data[i]->object;
		engine_entity->EnginePreUpdate ();
	}
	
	
	//?
	//? ─── ENTITY UPDATE ──────────────────────────────────────────────────────────────
	//?
	
	for (int i = 0; i < entities.data.size(); i++)
	{
		Entity* entity = (Entity*)entities.data[i]->object;
		entity->Update ();
	}
	
	//?
	//? ─── ENGINE POST UPDATE ─────────────────────────────────────────────────────────
	//?
	
	for (int i = 0; i < engine_entities.data.size(); i++)
	{
		EngineEntity* engine_entity = (EngineEntity*)engine_entities.data[i]->object;
		engine_entity->EnginePostUpdate ();
	}
	
	
	//? ────────────────────────────────────────────────────────────────────────────────
	
	// Removed all duplicates in the remove_stack
	std::sort (remove_stack.begin(), remove_stack.end());
	remove_stack.erase (std::unique(remove_stack.begin (), remove_stack.end()), remove_stack.end());
	
	// Sort the SafeVectors and fill the static "new_entities" vector above
	std::vector<Master*> _new_entities = this->entities.Sort(remove_stack);
	new_entities.insert (new_entities.end(), _new_entities.begin(), _new_entities.end());
	std::vector<Master*> _new_engine_entities = this->engine_entities.Sort(remove_stack);
	
	
	// Delete the cached masters
	for (int i = 0; i < remove_stack.size (); i++)
	{
		Master* master = remove_stack[i];
		delete master;
	}
	
	CalculateRemoveStack ();
	
	
	// this->renderers.Sort ();
	
	
	
	// Log the FPS every second.
	
	static float last_time = 0;
	static int frames = 0;
	frames++;
	
	if (Time::time - last_time >= 1.0f)
	{
		Log (INFO, "FPS: ", YELLOW, frames);
		
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
	
	static Transform transform;
	
	Graphics::DrawQuad(camera, &transform, blend_material);
	
	
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

void Engine::InitializeSelfReference (Master* master)
{
	// Set a reference to itself
	master->object->engine_data.master = master;
}

void Engine::RegisterObject (Master* entity)
{
	
	// Give the entity a Master reference to itself
	InitializeSelfReference (entity);
	
	// Add the master to the appropriate array base on its 
	
	if (entity->object->GetFlag(ENTITY))
	{
		this->entities.Add (entity);
	}
	if (entity->object->GetFlag(ENGINE_ENTITY))
	{
		this->engine_entities.Add (entity);
	}
	if (entity->object->GetFlag(RENDERER))
	{
		renderers.Add (entity);
	}
}

void Engine::DestroyObject (Master* master)
{
	remove_stack.push_back (master);
}

void Engine::CalculateRemoveStack ()
{
	Util::RemoveVectorFromVector<Master*> (entities.data, remove_stack);
	Util::RemoveVectorFromVector<Master*> (engine_entities.data, remove_stack);
	Util::RemoveVectorFromVector<Master*> (renderers.data, remove_stack);
	
	remove_stack.clear ();
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
