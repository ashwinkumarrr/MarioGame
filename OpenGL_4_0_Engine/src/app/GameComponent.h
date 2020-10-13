#ifndef GAME_COMPONENT_H
#define GAME_COMPONENT_H

#include "../managers/EntityManager.h"

class GameComponent
{
public:
	GameComponent();
	virtual ~GameComponent();

	virtual void Initialize();

	
	virtual void Update(float dt);

	virtual void Render(SpriteBatch* spriteBatch, Camera* camera);


	virtual void Release()=0;

	Entity* AddEntity();

private:
	static GameComponent* m_instance;

	EntityManager m_entityManger;
};

#endif
