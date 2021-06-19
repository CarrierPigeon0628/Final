#include "character.h"
bool knight::init()
{
	this->HP = MAX_HP;
	this->MP = MAX_MP;
	this->Armour = MAX_ARMOUR;
	this->gold = 0;
	this->Speed;
	return true;
}
knight* knight::create(const char* picFileName)
{
	knight* sprite = new knight();

	if (sprite && sprite->initWithFile(picFileName))

	{
		sprite->autorelease(); return sprite;
	}

	CC_SAFE_DELETE(sprite);
	return nullptr;
}

bool paladin::init()
{
	this->HP = MAX_HP;
	this->MP = MAX_MP;
	this->Armour = MAX_ARMOUR;
	this->gold = 0;
	this->Speed;
	return true;
}
paladin* paladin::create(const char* picFileName)
{
	paladin* sprite = new paladin();

	if (sprite && sprite->initWithFile(picFileName))

	{
		sprite->autorelease(); return sprite;
	}

	CC_SAFE_DELETE(sprite);
	return nullptr;
}

bool rogue::init()
{
	this->HP = MAX_HP;
	this->MP = MAX_MP;
	this->Armour = MAX_ARMOUR;
	this->gold = 0;
	this->Speed;
	return true;
}
rogue* rogue::create(const char* picFileName)
{
	rogue* sprite = new rogue();

	if (sprite && sprite->initWithFile(picFileName))

	{
		sprite->autorelease(); return sprite;
	}

	CC_SAFE_DELETE(sprite);
	return nullptr;
}

bool assassin::init()
{
	this->HP = MAX_HP;
	this->MP = MAX_MP;
	this->Armour = MAX_ARMOUR;
	this->gold = 0;
	this->Speed;
	return true;
}
assassin* assassin::create(const char* picFileName)
{
	assassin* sprite = new assassin();

	if (sprite && sprite->initWithFile(picFileName))

	{
		sprite->autorelease(); return sprite;
	}

	CC_SAFE_DELETE(sprite);
	return nullptr;
}

bool wizard::init()
{
	this->HP = MAX_HP;
	this->MP = MAX_MP;
	this->Armour = MAX_ARMOUR;
	this->gold = 0;
	this->Speed;
	return true;
}
wizard* wizard::create(const char* picFileName)
{
	wizard* sprite = new wizard();

	if (sprite && sprite->initWithFile(picFileName))

	{
		sprite->autorelease(); return sprite;
	}

	CC_SAFE_DELETE(sprite);
	return nullptr;
}
