#version 450 core

uniform mat4 worldMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;

layout(location = 0) in vec3 vertex_modelSpace;
layout(location = 1) in vec2 textureCoord_modelSpace;

out vec2 texCoord;


void main(void)
{

mat4 mvp = projectionMatrix * viewMatrix * worldMatrix;
gl_Position = mvp *vec4(vertex_modelSpace, 1.0);

texCoord = textureCoord_modelSpace;
texCoord.y = 1.0 - texCoord.y;

}