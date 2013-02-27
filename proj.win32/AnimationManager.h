#pragma once

#include "Inc.h"

using namespace cocos2d;

class AnimationManager : public Singleton<AnimationManager>
{
public:
	AnimationManager();
	~AnimationManager();
	//初始化动画模版缓存表
	bool initAnimationMap();
	//获取指定动画模版
	CCAnimation *getAnimation(int key);
	//创建动画实例
	CCAnimate *createAnimate(int key);
protected:
	//加载英雄行走动画模版
	CCAnimation *createHeroMovingAnimationByDirection(HeroDirection direction);
};

//定义动画管理器实例的别名
#define sAnimationManager AnimationManager::instance()