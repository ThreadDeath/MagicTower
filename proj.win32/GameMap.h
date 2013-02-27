#pragma once

#include "Inc.h"

using namespace cocos2d;

class GameMap : public CCTMXTiledMap
{
	//ֻ����������ȡ�ذ���ǽ�ڲ�
	CC_PROPERTY_READONLY(CCTMXLayer*, floorLayer, FloorLayer);
	CC_PROPERTY_READONLY(CCTMXLayer*, wallLayer, WallLayer);
public:
	GameMap(void);
	~GameMap(void);
	//��̬��������������GameMapʵ��
	static GameMap *gameMapWithTMXFile(const char *tmxFile);
	//����ת��
	CCPoint tileCoordForPosition(CCPoint position);
	CCPoint positionForTileCoord(CCPoint tileCoord);
protected:
	//����ĳ�ʼ������
	void extraInit();
	//������ͼ�㿹���
	void enableAnitiAliasForEachLayer();
};
