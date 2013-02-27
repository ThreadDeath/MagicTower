#include "GameLayer.h"

GameLayer::GameLayer(void)
{
	sGlobal->gameLayer = this;
}

GameLayer::~GameLayer(void)
{
}

bool GameLayer::init()
{
	bool bRet = false;
	do 
	{
		map = GameMap::gameMapWithTMXFile("0.tmx");
		this->addChild(map, kZMap, kZMap);

		hero = Hero::heroWithinLayer();
		hero->setPosition(map->positionForTileCoord(ccp(1, 11)));
		this->addChild(hero);

		bRet = true;
	} while (0);

	return bRet;
}