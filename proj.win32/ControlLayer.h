#pragma once

#include "Inc.h"

using namespace cocos2d;

class ControlLayer : public CCLayer
{
public:
	ControlLayer(void);
	~ControlLayer(void);
	virtual bool init();
	//����ť����ص�����
	void menuCallBackMove(CCObject *pSender);
	//�رհ�ť����ص�����
//	void menuCallBackClose(CCObject *pSender);
	CREATE_FUNC(ControlLayer);
};
