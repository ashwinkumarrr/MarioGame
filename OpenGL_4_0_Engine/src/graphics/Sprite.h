#ifndef SPRITE_H
#define SPRITE_H

#include "../Component.h"
#include <graphics\Camera.h>
#include <graphics\SpriteBatch.h>
#include "../graphics/RecTangle.h"

class TextureLoader;
class Shader;

class Sprite : public Component
{

public:

	Sprite(Entity* entity );
	~Sprite();

	
	void Render(SpriteBatch* spriteBatch, Camera* camera);   //override 

	void SetTextureFromFileName(const char* fileName);
	void SetShaderFromFileName(const char* fileName);

private:

	RecTangle m_rect;
	TextureLoader* m_texture;
	Shader* m_shader;

};
#endif