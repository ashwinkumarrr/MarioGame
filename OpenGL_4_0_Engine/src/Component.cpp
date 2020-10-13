#include "Component.h"
#include "Entity.h"
#include"graphics/SpriteBatch.h"
#include "graphics/Camera.h"

Component::Component(Entity* entity)
{
	m_entity = entity;
	if (m_entity)
		m_entity->AddComponent(this);
}

Component::~Component()
{

}

void Component::Intialize()
{
	m_hasBeenIntialized = true;
}

void Component::Update(float dt)
{
	(void)dt;
	if (!m_hasBeenIntialized) 
	{
		Intialize();
	}
}

void Component::Render(SpriteBatch* spriteBatch, Camera* camera)
{
	(void)spriteBatch;
	(void)camera;

	if (!m_hasBeenIntialized)
	{
		Intialize();
	}
}