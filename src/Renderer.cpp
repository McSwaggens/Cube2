#include "Renderer.h"

#include "Graphics.h"
#include "Camera.h"
#include "OpenGL.h"
#include "Engine.h"

Renderer::Renderer(Transform* transform, Material* material, RenderShape rendershape)
{
	this->transform = transform;
	this->material = material;
	this->rendershape = rendershape;
	
	// engine->Register (this);
}

Renderer::~Renderer ()
{
	// engine->Destroy (this);
}

void Renderer::Render (Camera* camera)
{
	if (rendershape == RENDERSHAPE_NONE)
	{
		return;
	}
	
	switch (rendershape)
	{
		case RENDERSHAPE_SQUARE:
		{
			Graphics::DrawQuad (camera, transform, material);
			return;
		}
	}
}
