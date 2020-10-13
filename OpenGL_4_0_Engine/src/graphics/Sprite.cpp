#include "Sprite.h"
#include "../managers/TextureManager.h"
#include "../managers/ShaderManager.h"
#include <assert.h>
#include "Camera.h"
#include "../graphics/SpriteBatch.h"
#include "../Component.h"
#include "../Entity.h"


Sprite::Sprite(Entity* entity) :
	Component(entity)
{

}

Sprite::~Sprite()
{

}

void Sprite::Render(SpriteBatch* spriteBatch, Camera* camera)
{
	m_shader->BeginShader();

	Vector3 scale = m_entity->GetScale();
	Matrix4x4 world, translation, scaleMat, viewMat;
	translation.BuildTranslation(m_entity->GetPosition());
	scaleMat.BuildScale(scale.GetX(), scale.GetY(), 1.0f);

	world = translation * scaleMat;

	m_shader->SetShaderMatrixParameter("worldMatrix", world.AsArray());
	m_shader->SetShaderMatrixParameter("projectionMatrix", camera->GetOrthoMatrix().AsArray());
	m_shader->SetShaderMatrixParameter("viewMatrix", viewMat.AsArray());

	m_shader->SetShaderSampler("shaderTexture", 0, m_texture);

	spriteBatch->Draw(m_rect);

	m_shader->EndShader();
    
}

void Sprite::SetTextureFromFileName(const char* fileName)
{
	m_texture = TextureManager::GetInstance()->GetTexture(fileName);
	assert(m_texture);

	m_rect = RecTangle(0.0f, 0.0f, (float)m_texture->GetWidth(), (float)m_texture->GetHeight());

}

void Sprite::SetShaderFromFileName(const char* fileName)
{
	m_shader = ShaderManager::GetInstance()->GetShader(string(fileName));
	assert(m_shader);
}