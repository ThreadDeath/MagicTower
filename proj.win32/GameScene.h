#pragma once

#include "Inc.h"

using namespace cocos2d;

class GameScene : public CCScene
{
public:
	GameScene();
	~GameScene();
	static CCScene *playNewGame();
	virtual bool init();
	CREATE_FUNC(GameScene);
};