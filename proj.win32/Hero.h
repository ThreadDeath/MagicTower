#pragma once

#include "Inc.h"

using namespace cocos2d;

class Hero : public CCNode
{
public:
	Hero();
	~Hero();
	//静态方法，用于创建勇士实例
	static Hero *heroWithinLayer();
	bool heroInit();
	CCSprite *heroSprite;
	bool isHeroMoving;
	void move(HeroDirection direction);
	void onMoveDone(CCNode *pTarget, void *data);
	void setFaceDirection(HeroDirection direction);
//	CollisionType checkCollision(CCPoint heroPosition);
};
