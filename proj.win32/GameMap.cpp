#include "GameMap.h"

GameMap::GameMap(void)
{
	sGlobal->gameMap = this;
}

GameMap::~GameMap(void)
{
}

CCTMXLayer *GameMap::getFloorLayer()
{
	return floorLayer;
}

CCTMXLayer *GameMap::getWallLayer()
{
	return wallLayer;
}

GameMap *GameMap::gameMapWithTMXFile(const char *tmxFile)
{
	GameMap *pRet = new GameMap();
	if(pRet->initWithTMXFile(tmxFile))
	{
		pRet->extraInit();
		pRet->autorelease();
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
	return NULL;
}

void GameMap::extraInit()
{
	enableAnitiAliasForEachLayer();

	floorLayer = this->layerNamed("floor");
	wallLayer = this->layerNamed("wall");
}

void GameMap::enableAnitiAliasForEachLayer()
{
	CCArray *pChildrenArray = this->getChildren();
	CCSpriteBatchNode *child = NULL;
	CCObject *pObject = NULL;

	CCARRAY_FOREACH(pChildrenArray, pObject)
	{
		child = (CCSpriteBatchNode *)pObject;
		if(!child)
		{
			break;
		}
		child->getTexture()->setAliasTexParameters();
	}
}

//从cocos2d-x坐标转换为Tilemap坐标
CCPoint GameMap::tileCoordForPosition(CCPoint position)
{
	int x = position.x / this->getTileSize().width;
	int y = (((this->getMapSize().height - 1) * this->getTileSize().height) - position.y) / this->getTileSize().height;
	return ccp(x, y);
}

//从Tilemap坐标转换为cocos2d-x坐标
CCPoint GameMap::positionForTileCoord(CCPoint tileCoord)
{
	CCPoint pos =  ccp((tileCoord.x * this->getTileSize().width),
		((this->getMapSize().height - tileCoord.y - 1) * this->getTileSize().height));
	return pos;
}