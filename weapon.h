#include "cocos2d.h"
USING_NS_CC;
class quickgun :public cocos2d::Sprite
{
public:
	virtual bool quickgun::init();
	static quickgun* create(const char* picFileName);
	static cocos2d::Point GetTarget(cocos2d::Point start, cocos2d::Point end, int Xout, int Yout);
};

class submachinegun :public cocos2d::Sprite
{
public:
	virtual bool submachinegun::init();
	static submachinegun* create(const char* picFileName);
	static cocos2d::Point TargetRotation(cocos2d::Point start, cocos2d::Point end, float angle);
	static cocos2d::Point GetTarget(cocos2d::Point start, cocos2d::Point end, int Xout, int Yout);
};

class sword :public cocos2d::Sprite
{
public:
	virtual bool sword::init();
	static sword* create(const char* picFileName);
	int harm = 5;
};

class magicsword :public cocos2d::Sprite
{
public:
	virtual bool magicsword::init();
	static magicsword* create(const char* picFileName);
	int harm = 5;
};

class bullet :public cocos2d::Sprite
{
public:
	virtual bool init();
	static bullet* create(const char* picFileName);
	int harm = 5;
};

class magic :public cocos2d::Sprite
{
public:
	virtual bool init();
	static magic* create(const char* picFileName);
	int harm = 5;
};
