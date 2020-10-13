#include "Entity.h"
#include "Component.h"

Entity::Entity()
{
	m_position.Set();
	m_scale = Vector3(1.0f, 1.0f, 1.0f);
	m_velocity.Set();
}

const int& Entity::GetID() const
{
	return m_id;
}

Entity::~Entity()
{

}

void Entity::Initialize()
{
	m_hasBeenInitialized = true;
}

void Entity::Update(float dt)
{
	for (unsigned int i = 0; i < m_components.size(); ++i)
	{
		m_components [i]->Update(dt);
	}

	m_position += m_velocity * dt;
}

void Entity::render(SpriteBatch* spriteBatch, Camera* camera)
{
	for (unsigned int i = 0; i < m_components.size(); ++i)
	{
		m_components[i]->Render(spriteBatch, camera);
	}
}

void Entity::AddComponent(Component* component)
{
	if (!component) return;
	m_components.push_back(component);
}

void Entity::RemoveComponent(Component* component)
{
	if (!component) return;

	for (unsigned int i = 0; i < m_components.size(); ++i)
	{
		if (m_components[i] == component)
		{
			m_components.erase(m_components.begin() + i);
			delete component;
			component = NULL;
		}
	}
}

const Vector3& Entity::GetPosition() const
{
	return m_position;
}

const Vector3& Entity::GetScale() const
{
	return m_scale;
}

const Vector3& Entity::GetVelocity() const
{
	return m_velocity;
}

const bool& Entity::HasBeenInstialized() const
{
	return m_hasBeenInitialized;
}

void Entity::SetPosition(float x, float y, float z)
{
	m_position.Set(x, y, z);
}

void Entity::SetScale(float x, float y, float z)
{
	m_scale.Set(x, y, z);
}

void Entity::SetVelocity(float x, float y, float z)
{
	m_velocity.Set(x, y, z);
}