#include "GameComponent.h"

GameComponent* GameComponent::m_instance;

GameComponent::GameComponent()
{
	m_instance = this;
}

GameComponent::~GameComponent()
{
}

void GameComponent::Initialize()
{
	m_entityManger.Intialize();
}

void GameComponent::Update(float dt)
{
	m_entityManger.Update(dt);
}

void GameComponent::Render(SpriteBatch* spriteBatch, Camera* camera)
{
	m_entityManger.Render(spriteBatch, camera);
}

Entity* GameComponent::AddEntity()
{
	return m_entityManger.AddEntity();
}
