#pragma once

#include "Inc.h"

using namespace cocos2d;

class GameLayer;
class GameMap;
class Hero;

class Global : public Singleton<Global>
{
public:
	Global();
	~Global();

	//游戏主图层
	GameLayer *gameLayer;

	//游戏地图
	GameMap *gameMap;

	//勇士
	Hero *hero;
};

#define sGlobal Global::instance()