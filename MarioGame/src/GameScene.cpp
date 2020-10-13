#include "GameScene.h"
#include "graphics/Sprite.h"
#include "app/Engine.h"
#include "Player.h"

GameScene::GameScene()
{

}

GameScene::~GameScene()
{

}

void GameScene::Initialize()
{
	GameComponent::Initialize();

	Engine::GetEngine()->InitializeTextureManager();

	TextureManager::GetInstance()->SetRootDirectory("Textures/");
	TextureManager::GetInstance()->AddTexture("mario_walking", ".png", "mario");

	Engine::GetEngine()->InitializeShaderManager();
	ShaderManager::GetInstance()->AddShader("texture", "TEXTURE");

	{
		Entity* entity = AddEntity();
		Engine::GetEngine()->InitializeCamera(entity, 0.0f, 1.0f);
	}

	{
		Entity* entity = AddEntity();
		entity->SetPosition(100, 100);

		Sprite* sprite = new Sprite(entity);
		sprite->SetTextureFromFileName("mario");
		sprite->SetShaderFromFileName("TEXTURE");

		Player* player = new Player(entity);

	}
}

void GameScene::Update(float dt)
{
	GameComponent::Update(dt);
}

void GameScene::Render(SpriteBatch* spriteBatch, Camera* camera)
{
	GameComponent::Render(spriteBatch, camera);
}

void GameScene::Release()
{

}
