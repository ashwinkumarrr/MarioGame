#ifndef COMPONENT_H
#define COMPONENT_H

class Entity;
class SpriteBatch;
class Camera;

class Component
{
public:
	Component(Entity* entity);
	~Component();

	virtual void Intialize();
	virtual void Update(float dt);
	virtual void Render(SpriteBatch* spriteBatch, Camera* camera);

protected:

	Entity* m_entity;
	bool m_hasBeenIntialized{ false};

};
#endif