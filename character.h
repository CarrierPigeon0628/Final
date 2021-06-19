#include "cocos2d.h"
USING_NS_CC;
class knight : public cocos2d::Sprite
{
public:
	int HP, MP, Armour, Speed = 5, gold;
	virtual bool init();
	static knight* create(const char* picFileName);
private:
	const int MAX_HP = 7, MAX_MP = 200, MAX_ARMOUR = 6;
};

class paladin : public cocos2d::Sprite
{
public:
	int HP, MP, Armour, Speed = 5, gold;
	virtual bool init();
	static paladin* create(const char* picFileName);
private:
	const int MAX_HP = 2, MAX_MP = 140, MAX_ARMOUR = 9;
};

class rogue : public cocos2d::Sprite
{
public:
	int HP, MP, Armour, Speed = 5, gold;
	virtual bool init();
	static rogue* create(const char* picFileName);
private:
	const int MAX_HP = 6, MAX_MP = 200, MAX_ARMOUR = 4;
};

class assassin : public cocos2d::Sprite
{
public:
	int HP, MP, Armour, Speed = 5, gold;
	virtual bool init();
	static assassin* create(const char* picFileName);
private:
	const int MAX_HP = 5, MAX_MP = 200, MAX_ARMOUR = 5;
};

class wizard : public cocos2d::Sprite
{
public:
	int HP, MP, Armour, Speed = 5, gold;
	virtual bool init();
	static wizard* create(const char* picFileName);
private:
	const int MAX_HP = 4, MAX_MP = 260, MAX_ARMOUR = 6;
};