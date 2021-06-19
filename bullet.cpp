#include"bullet.h"
bool bullet::init()
{
	this->harm;
	return true;
}
bullet* bullet::create(const char* picFileName)
{
	bullet* sprite = new bullet();

	if (sprite && sprite->initWithFile(picFileName))

	{
		sprite->autorelease();
		return sprite;
	}

	CC_SAFE_DELETE(sprite);
	return nullptr;
}