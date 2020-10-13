
#include "app\FrameWork.h"
#include "GameScene.h"

void main()
{
	// Update game loop

	FrameWork framework;
	framework.Initialize(new GameScene(), "MarioGame");
	framework.Run();



	return;

}
