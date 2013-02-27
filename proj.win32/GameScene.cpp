#include "GameScene.h"

GameScene::GameScene()
{

}

GameScene::~GameScene()
{

}

bool GameScene::init()
{
	GameLayer *gamelayer = GameLayer::create();
	this->addChild(gamelayer, kGameLayer, kGameLayer);

	ControlLayer *controlLayer = ControlLayer::create();
	this->addChild(controlLayer, kControlLayer, kControlLayer);

	return true;
}

CCScene *GameScene::playNewGame()
{
	GameScene *scene = NULL;
	do 
	{
		scene = GameScene::create();
		CC_BREAK_IF(!scene);
	} while (0);
	
	return scene;
}