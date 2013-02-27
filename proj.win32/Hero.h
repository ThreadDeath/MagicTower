#pragma once

#include "Inc.h"

using namespace cocos2d;

class Hero : public CCNode
{
public:
	Hero();
	~Hero();
	//��̬���������ڴ�����ʿʵ��
	static Hero *heroWithinLayer();
	bool heroInit();
	CCSprite *heroSprite;
	bool isHeroMoving;
	void move(HeroDirection direction);
	void onMoveDone(CCNode *pTarget, void *data);
	void setFaceDirection(HeroDirection direction);
//	CollisionType checkCollision(CCPoint heroPosition);
};
