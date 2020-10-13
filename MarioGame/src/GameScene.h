#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "app/GameComponent.h"


class GameScene :
	public GameComponent

{
public:
	GameScene();
	virtual ~GameScene();

	
	 void Initialize() override;

	void Update(float dt) override;

	void Render(SpriteBatch* spriteBatch, Camera* camera) override;

	void Release() override;

};
#endif
