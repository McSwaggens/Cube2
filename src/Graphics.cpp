#include "Graphics.h"

#include "OpenGL.h"


//?
//? ─── GRAPHICS ───────────────────────────────────────────────────────────────────
//?

GLuint line_uv_buffer_id;
const GLfloat uv_buffer_1d_data[] =
{
	0.0f, 1.0f
};

void Graphics::InitGraphics ()
{
	//?
	//? ─── LINE UV BUFFER ─────────────────────────────────────────────────────────────
	//?
	
	glGenBuffers (1, &line_uv_buffer_id);
	glBindBuffer (GL_ARRAY_BUFFER, line_uv_buffer_id);
	glBufferData (GL_ARRAY_BUFFER, sizeof(uv_buffer_1d_data), uv_buffer_1d_data, GL_STATIC_DRAW);
	
	
	//? ────────────────────────────────────────────────────────────────────────────────

}

void Graphics::DrawQuad (Camera* camera, Transform* transform, Material* material)
{
	
}

void Graphics::DrawLineRaw (Vector a, Vector b, Material* material)
{
	
	GLfloat line_vertex_buffer[] =
	{
		a.x, a.y, 0.0f,
		b.x, b.y, 0.0f
	};
	
	GLuint line_vertex_buffer_id;
	glGenBuffers (1, &line_vertex_buffer_id);
	glBindBuffer (GL_ARRAY_BUFFER, line_vertex_buffer_id);
	glBufferData (GL_ARRAY_BUFFER, sizeof(line_vertex_buffer), line_vertex_buffer, GL_STATIC_DRAW);
	
	material->Enable(mat4(1));
	
	
	glEnableVertexAttribArray (0);
	glBindBuffer (GL_ARRAY_BUFFER, line_vertex_buffer_id);
	glVertexAttribPointer
	(
		0,
		3,
		GL_FLOAT,
		GL_FALSE,
		0,
		(void*)0
	);
	
	glEnableVertexAttribArray (1);
	glBindBuffer (GL_ARRAY_BUFFER, line_uv_buffer_id);
	glVertexAttribPointer
	(
		1,
		2,
		GL_FLOAT,
		GL_FALSE,
		0,
		(void*)0
	);
	
	
	glDrawArrays (GL_LINES, 0, 2);
	
	
	material->Disable();
	
	glDisableVertexAttribArray (0);
	glDisableVertexAttribArray (1);
	
	glDeleteBuffers (1, &line_vertex_buffer_id);
	
}

void Graphics::DrawLine (Camera* camera, Vector a, Vector b, Material* material)
{
	Vector ra = camera->GetReal (a);
	Vector rb = camera->GetReal (b);
	
	DrawLineRaw (ra, rb, material);
}

//? ────────────────────────────────────────────────────────────────────────────────
