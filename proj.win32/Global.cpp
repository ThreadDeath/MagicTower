#include "Global.h"

DECLARE_SINGLETON_MEMBER(Global);

Global::Global()
{

}

Global::~Global()
{
	gameLayer = NULL;
	gameMap = NULL;
	hero = NULL;
}