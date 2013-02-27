#include "Hero.h"

Hero::Hero()
{
	sGlobal->hero = this;
}

Hero::~Hero()
{
}

Hero *Hero::heroWithinLayer()
{
	Hero *pRet = new Hero();
	if(pRet && pRet->heroInit())
	{
		pRet->autorelease();
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
	return NULL;
}

bool Hero::heroInit()
{
	//创建初始帧，默认为向下行走的动画
	heroSprite = CCSprite::spriteWithSpriteFrame(((CCAnimationFrame *)(sAnimationManager->getAnimation(kDown)->getFrames()->objectAtIndex(0)))->getSpriteFrame());
	heroSprite->setAnchorPoint(CCPointZero);
	this->addChild(heroSprite);

	isHeroMoving = false;
	return true;
}

void Hero::move(HeroDirection direction)
{
	if(isHeroMoving)
	{
		return;
	}

	CCPoint moveByPosition;
	//根据方向计算移动的距离
	switch (direction)
	{
	case kDown:
		moveByPosition = ccp(0, -32);
		break;
	case kLeft:
		moveByPosition = ccp(-32, 0);
		break;
	case kRight:
		moveByPosition = ccp(32, 0);
		break;
	case kUp:
		moveByPosition = ccp(0, 32);
		break;
	}

	CCPoint targetPosition = ccpAdd(this->getPosition(), moveByPosition);
/*	if(checkCollision(targetPosition) == kWall)
	{
		setFaceDirection((HeroDirection)direction);
		return;
	}*/

	heroSprite->runAction(sAnimationManager->createAnimate(direction));
	CCAction *action = CCSequence::actions(CCMoveBy::actionWithDuration(0.20f, moveByPosition),
		CCCallFuncND::actionWithTarget(this,
		callfuncND_selector(Hero::onMoveDone), (void *)direction),
		NULL);
	this->runAction(action);
	isHeroMoving = true;
}

/*CollisionType Hero::checkCollision(CCPoint heroPosition)
{
	targetTile
}*/

void Hero::setFaceDirection(HeroDirection direction)
{
	heroSprite->setTextureRect(CCRectMake(0, BLOCK_SIZE*direction, BLOCK_SIZE, BLOCK_SIZE));
}

void Hero::onMoveDone(CCNode *pTarget, void *data)
{
	int direction = (int)data;
	setFaceDirection((HeroDirection)direction);
	isHeroMoving = false;
	//sGlobal->gameLayer->setSceneScrollPosition(this->getPosition());
}