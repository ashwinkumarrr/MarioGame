#include "Player.h"
#include "app/Engine.h"

Player::Player(Entity* entity) :
	Component(entity)
{
	m_speed = 10.0f;
}

Player::~Player()
{

}

void Player::Update(float dt)
{
	input_manager* input = Engine::GetEngine()->GetInput();

	Vector3 vel = m_entity->GetVelocity();

	if (input->IsKeyDown(KeyPad::KEY_A))
	{
		vel += Vector3(-m_speed, 0.0f, 0.0f);
	}
	else if (input->IsKeyDown(KeyPad::KEY_D))
	{
		vel += Vector3(m_speed, 0.0f, 0.0f);
	}

	if (vel.GetX() > MaxHorizontalVelocity)
	{
		vel.SetX(MaxHorizontalVelocity);
	}
	else if (vel.GetX() < -MaxHorizontalVelocity)
	{
		vel.SetX(-MaxHorizontalVelocity);
	}


	m_entity->SetVelocity(vel.GetX() * Friction, vel.GetY(), 0.0f);
}