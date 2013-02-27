#pragma once

#include "Inc.h"

using namespace cocos2d;

class ControlLayer : public CCLayer
{
public:
	ControlLayer(void);
	~ControlLayer(void);
	virtual bool init();
	//方向按钮点击回调函数
	void menuCallBackMove(CCObject *pSender);
	//关闭按钮点击回调函数
//	void menuCallBackClose(CCObject *pSender);
	CREATE_FUNC(ControlLayer);
};
