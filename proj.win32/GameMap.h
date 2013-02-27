#pragma once

#include "Inc.h"

using namespace cocos2d;

class GameMap : public CCTMXTiledMap
{
	//只读变量，获取地板层和墙壁层
	CC_PROPERTY_READONLY(CCTMXLayer*, floorLayer, FloorLayer);
	CC_PROPERTY_READONLY(CCTMXLayer*, wallLayer, WallLayer);
public:
	GameMap(void);
	~GameMap(void);
	//静态方法，用于生成GameMap实例
	static GameMap *gameMapWithTMXFile(const char *tmxFile);
	//坐标转换
	CCPoint tileCoordForPosition(CCPoint position);
	CCPoint positionForTileCoord(CCPoint tileCoord);
protected:
	//额外的初始化方法
	void extraInit();
	//开启各图层抗锯齿
	void enableAnitiAliasForEachLayer();
};
