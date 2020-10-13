#version 450 core

uniform sampler2D shaderTexture;

in vec2 texCoord;

out vec4 FragColor;

void main(void)
{
  FragColor = texture(shaderTexture, texCoord);
}