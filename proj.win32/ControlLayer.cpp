#include "ControlLayer.h"

ControlLayer::ControlLayer(void)
{
}

ControlLayer::~ControlLayer(void)
{
}

bool ControlLayer::init()
{
	if(!CCLayer::init())
	{
		return false;
	}

	//创建方向按钮
	CCMenuItem *up = CCMenuItemFont::itemWithString("up", this, menu_selector(ControlLayer::menuCallBackMove));
	CCMenuItem *down = CCMenuItemFont::itemWithString("down", this, menu_selector(ControlLayer::menuCallBackMove));
	CCMenuItem *left = CCMenuItemFont::itemWithString("left", this, menu_selector(ControlLayer::menuCallBackMove));
	CCMenuItem *right = CCMenuItemFont::itemWithString("right", this, menu_selector(ControlLayer::menuCallBackMove));
	up->setTag(kUp);
	down->setTag(kDown);
	left->setTag(kLeft);
	right->setTag(kRight);
	CCMenu *menu = CCMenu::menuWithItems(up, down, left, right, NULL);
	
	//排列按钮
	menu->alignItemsHorizontallyWithPadding(50);
	this->addChild(menu);

	return true;
}

void ControlLayer::menuCallBackMove(CCObject *pSender)
{
	CCNode *node = (CCNode *)pSender;
	int targetDirection = node->getTag();
	sGlobal->hero->move((HeroDirection)targetDirection);
}