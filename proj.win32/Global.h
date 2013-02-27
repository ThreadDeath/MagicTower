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

	//��Ϸ��ͼ��
	GameLayer *gameLayer;

	//��Ϸ��ͼ
	GameMap *gameMap;

	//��ʿ
	Hero *hero;
};

#define sGlobal Global::instance()