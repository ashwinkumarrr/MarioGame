#ifndef ENTITY_H
#define ENTITY_H

#include <vector>
#include "maths/MathCore.h"

class Component;
class SpriteBatch;
class Camera;

class Entity
{
public:

	friend class EntityManager;
	~Entity();

	void Initialize();
	void Update(float dt);
	void render(SpriteBatch* spriteBatch, Camera* camera);

	void AddComponent(Component* component);
	void RemoveComponent(Component* component);

	const Vector3& GetPosition()const;
	const Vector3& GetScale()const;
	const Vector3& GetVelocity()const;
	const bool& HasBeenInstialized()const;


	void SetPosition(float x = 0.0f, float y = 0.0f, float z = 0.0f);
	void SetScale(float x = 0.0f, float y = 0.0f, float z = 0.0f);
	void SetVelocity(float x = 0.0f, float y = 0.0f, float z = 0.0f);

private:

	Entity();

	std::vector<Component*> m_components;

	const int& GetID()const;

	Vector3 m_position;
	Vector3 m_scale;
	Vector3 m_velocity;

	int m_id{ -1 };
	bool m_hasBeenInitialized{ false };

};
#endif