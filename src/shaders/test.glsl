#version 330 core

#vert
layout (location = 0) in vec3 vertexPosition_modelspace;

uniform mat4 MVP;

void main ()
{
	gl_Position = MVP * vec4(vertexPosition_modelspace.xy, 0, 1);
}


#frag
out vec3 color;

void main ()
{
	color = vec3(1,1,1);
}