#include "AnimationManager.h"

DECLARE_SINGLETON_MEMBER(AnimationManager);

AnimationManager::AnimationManager()
{

}

AnimationManager::~AnimationManager()
{

}

bool AnimationManager::initAnimationMap()
{
	char temp[20];
	//加载向上动画
	sprintf_s(temp, "%d", aUp);
	CCAnimationCache::sharedAnimationCache()->addAnimation(createHeroMovingAnimationByDirection(kUp), temp);
	//加载向下动画
	sprintf_s(temp, "%d", aDown);
	CCAnimationCache::sharedAnimationCache()->addAnimation(createHeroMovingAnimationByDirection(kDown), temp);
	//加载向左动画
	sprintf_s(temp, "%d", aLeft);
	CCAnimationCache::sharedAnimationCache()->addAnimation(createHeroMovingAnimationByDirection(kLeft), temp);
	//加载向上动画
	sprintf_s(temp, "%d", aRight);
	CCAnimationCache::sharedAnimationCache()->addAnimation(createHeroMovingAnimationByDirection(kRight), temp);

	return true;
}

CCAnimation *AnimationManager::createHeroMovingAnimationByDirection(HeroDirection direction)
{
	CCTexture2D *heroTexture = CCTextureCache::sharedTextureCache()->addImage("hero.png");
	CCSpriteFrame *frame0, *frame1, *frame2, *frame3;

	frame0 = CCSpriteFrame::frameWithTexture(heroTexture, CCRectMake(BLOCK_SIZE*0, BLOCK_SIZE*direction, BLOCK_SIZE, BLOCK_SIZE));
	frame1 = CCSpriteFrame::frameWithTexture(heroTexture, CCRectMake(BLOCK_SIZE*1, BLOCK_SIZE*direction, BLOCK_SIZE, BLOCK_SIZE));
	frame2 = CCSpriteFrame::frameWithTexture(heroTexture, CCRectMake(BLOCK_SIZE*2, BLOCK_SIZE*direction, BLOCK_SIZE, BLOCK_SIZE));
	frame3 = CCSpriteFrame::frameWithTexture(heroTexture, CCRectMake(BLOCK_SIZE*3, BLOCK_SIZE*direction, BLOCK_SIZE, BLOCK_SIZE));
	CCArray *animFrames = new CCArray[4];
	animFrames->retain();
	animFrames->addObject(frame0);
	animFrames->addObject(frame1);
	animFrames->addObject(frame2);
	animFrames->addObject(frame3);

	CCAnimation *animation = new CCAnimation();
	animation->initWithSpriteFrames(animFrames, 0.05f);
	animFrames->release();

	return animation;
}

//获取指定动画模版
CCAnimation *AnimationManager::getAnimation(int key)
{
	char temp[20];
	sprintf_s(temp, 20, "%d", key);
	return CCAnimationCache::sharedAnimationCache()->animationByName(temp);
}

//播放动画实例
CCAnimate *AnimationManager::createAnimate(int key)
{
	CCAnimation *animation = getAnimation(key);
	if(animation)
	{
		return CCAnimate::actionWithAnimation(animation);
	}
	return NULL;
}

