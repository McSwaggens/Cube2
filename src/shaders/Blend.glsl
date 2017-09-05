#version 330 core

#vert
layout (location = 0) in vec3 vertexPosition_modelspace;
layout (location = 1) in vec2 vertexUV;


uniform mat4 MVP;
out vec2 UV;

void main ()
{
	gl_Position = MVP * vec4(vertexPosition_modelspace.xy, 0, 1);
	UV = vertexUV;
}


#frag
out vec4 color;
in vec2 UV;

uniform sampler2D tex;
uniform sampler2D tex2;

void main ()
{
	color = (texture(tex, UV)) * (texture(tex2, UV));
}