#include "Graphics.h"

#include "OpenGL.h"
#include "Defaults.h"

//?
//? ─── VARIABLES ──────────────────────────────────────────────────────────────────
//?

	//?
	//? ─── LINE ───────────────────────────────────────────────────────────────────────
	//?


	GLuint line_uv_buffer_id;
	const GLfloat uv_buffer_1d_data[] =
	{
		0.0f, 1.0f
	};

	//?
	//? ─── QUAD ───────────────────────────────────────────────────────────────────────
	//?
	
	GLuint uv_buffer_id;
	const GLfloat vertex_buffer_data[] =
	{
		-1.0f, -1.0f, 0.0f,
		1.0f, -1.0f, 0.0f,
		1.0f,  1.0f, 0.0f,
		
		1.0f,  1.0f, 0.0f,
		-1.0f, 1.0f, 1.0f,
		-1.0f, -1.0f, 0.0f,
	};
	
	GLuint vertex_buffer_id;
	const GLfloat uv_buffer_data[] =
	{
		0.0f, 0.0f,
		1.0f, 0.0f,
		1.0f, 1.0f,
		
		1.0f, 1.0f,
		0.0f, 1.0f,
		-0.0f, 0.0f,
	};
	
//? ────────────────────────────────────────────────────────────────────────────────


//?
//? ─── GRAPHICS ───────────────────────────────────────────────────────────────────
//?

void Graphics::InitGraphics ()
{
	//?
	//? ─── LINE UV BUFFER ─────────────────────────────────────────────────────────────
	//?
	
	glGenBuffers (1, &line_uv_buffer_id);
	glBindBuffer (GL_ARRAY_BUFFER, line_uv_buffer_id);
	glBufferData (GL_ARRAY_BUFFER, sizeof(uv_buffer_1d_data), uv_buffer_1d_data, GL_STATIC_DRAW);
	
	
	//? ────────────────────────────────────────────────────────────────────────────────
	
	
	glGenBuffers (1, &uv_buffer_id);
	glBindBuffer (GL_ARRAY_BUFFER, uv_buffer_id);
	glBufferData (GL_ARRAY_BUFFER, sizeof(uv_buffer_data), uv_buffer_data, GL_STATIC_DRAW);
	
	
	
	glGenBuffers (1, &vertex_buffer_id);
	glBindBuffer (GL_ARRAY_BUFFER, vertex_buffer_id);
	glBufferData (GL_ARRAY_BUFFER, sizeof(vertex_buffer_data), vertex_buffer_data, GL_STATIC_DRAW);
	
}

//?
//? ─── QUAD ───────────────────────────────────────────────────────────────────────
//?

void Graphics::DrawQuad (Camera* camera, Transform* transform, Material* material)
{
	//?
	//? ─── ENABLE OUR BUFFERS ─────────────────────────────────────────────────────────
	//?

	glEnableVertexAttribArray (0);
	glBindBuffer (GL_ARRAY_BUFFER, vertex_buffer_id);
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
	glBindBuffer (GL_ARRAY_BUFFER, uv_buffer_id);
	glVertexAttribPointer
	(
		1,
		2,
		GL_FLOAT,
		GL_FALSE,
		0,
		(void*)0
	);
	
	//?
	//? ─── DRAW OUR QUAD ──────────────────────────────────────────────────────────────
	//?

	
	mat4 mvp = camera->GenerateMVPMatrix (*transform);
	material->Enable (mvp);
	
	glDrawArrays (GL_TRIANGLES, 0, 6);
	
	material->Disable ();
	
	//?
	//? ─── DISABLE OUR BUFFERS ────────────────────────────────────────────────────────
	//?
	
	glDisableVertexAttribArray (0);
	glDisableVertexAttribArray (1);
	
	
	//? ────────────────────────────────────────────────────────────────────────────────
}

//?
//? ─── LINE ───────────────────────────────────────────────────────────────────────
//?


void Graphics::DrawLineRaw (Vector a, Vector b, Color color)
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
	
	
	color_material->in_color.data = color;
	color_material->Enable(mat4(1));
	
	
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
	
	
	color_material->Disable();
	
	glDisableVertexAttribArray (0);
	glDisableVertexAttribArray (1);
	
	glDeleteBuffers (1, &line_vertex_buffer_id);
	
}

void Graphics::DrawLine (Camera* camera, Vector a, Vector b, Color color)
{
	Vector ra = camera->GetReal (a);
	Vector rb = camera->GetReal (b);
	
	DrawLineRaw (ra, rb, color);
}

//? ────────────────────────────────────────────────────────────────────────────────
