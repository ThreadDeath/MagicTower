#pragma once

#include "Inc.h"

using namespace cocos2d;

class AnimationManager : public Singleton<AnimationManager>
{
public:
	AnimationManager();
	~AnimationManager();
	//��ʼ������ģ�滺���
	bool initAnimationMap();
	//��ȡָ������ģ��
	CCAnimation *getAnimation(int key);
	//��������ʵ��
	CCAnimate *createAnimate(int key);
protected:
	//����Ӣ�����߶���ģ��
	CCAnimation *createHeroMovingAnimationByDirection(HeroDirection direction);
};

//���嶯��������ʵ���ı���
#define sAnimationManager AnimationManager::instance()