#ifndef ENTITYMANAGER_H
#define ENTITIYMANAGER_H

#include "Entity.h"
#include <vector>

class EntityManager
{
public:
	EntityManager();
	~EntityManager();

	void Intialize();
	void Update(float dt);
	void Render(SpriteBatch* spriteBatch, Camera* camera);

	Entity* AddEntity();
	void RemoveEntity(Entity* entity);

private:

	std::vector<Entity*> m_entities;

};
#endif