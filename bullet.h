#include"cocos2d.h"
USING_NS_CC;
class bullet :public cocos2d::Sprite
{
public:
	virtual bool init();
	static bullet* create(const char* picFileName);
	int harm = 5;
};
