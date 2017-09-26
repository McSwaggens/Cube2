#version 330 core

#vert
layout (location = 0) in vec3 vertexPosition_modelspace;
layout (location = 1) in vec2 vertexUV;


uniform mat4 MVP;

void main ()
{
	gl_Position = vec4(vertexPosition_modelspace.xy, 0, 1);
}


#frag
out vec4 color;

uniform vec4 in_color;

void main ()
{
	color = in_color;
}