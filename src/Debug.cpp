#include "Debug.h"

#include <vector>
#include "Graphics.h"

//?
//? ─── DEBUG ──────────────────────────────────────────────────────────────────────
//?

struct DebugLine
{
	Camera* camera;
	Vector a;
	Vector b;
	Color color;
	
	DebugLine (Camera* camera, Vector a, Vector b, Color color)
	{
		this->camera = camera;
		this->a = a;
		this->b = b;
		this->color = color;
	}
};

std::vector<DebugLine> debug_lines;


void Debug::DrawLine (Camera* camera, Vector a, Vector b, Color color)
{
	DebugLine line (camera, a, b, color);
	debug_lines.push_back (line);
}

void Debug::EngineUpdateStart ()
{
	
}

void Debug::EngineUpdateEnd ()
{
	
	for (int i = 0; i < debug_lines.size(); i++)
	{
		DebugLine line = debug_lines[i];
		
		Graphics::DrawLine (line.camera, line.a, line.b, line.color);
	}
	
	
	
	debug_lines.clear ();
}




//? ────────────────────────────────────────────────────────────────────────────────
