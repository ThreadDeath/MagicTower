#pragma once

#include "Inc.h"

using namespace cocos2d;

class GameMap;
class Hero;

class GameLayer : public CCLayer
{
public:
	GameLayer(void);
	~GameLayer(void);
	virtual bool init();
	CREATE_FUNC(GameLayer);
protected:
	GameMap *map;
	Hero *hero;
};
