#ifndef PLAYER_H
#define PLAYER_H

#include "Component.h"


class Player : public Component
{
public:

	Player(Entity* entity);
	~Player();

	void Update(float dt);

private:

	const float MaxHorizontalVelocity = 150.0f;
	const float Friction = 0.96f;
	float m_speed;


};
#endif