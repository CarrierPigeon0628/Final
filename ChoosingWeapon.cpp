#include "ChoosingWeapon.h"
#include "ChoosingCharacter.h"
#include "Play11.h"
#include <string>

USING_NS_CC;

int ChoosingWeapon::characterDecision;
int ChoosingWeapon::weaponDecision[2];

Scene* ChoosingWeapon::createScene()
{
	return ChoosingWeapon::create();
}

bool ChoosingWeapon::init()
{
	if (!Scene::init())
	{
		return false;
	}

	characterDecision = ChoosingCharacter::decision;

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Sprite* background = Sprite::create("ChoosingWeapon.jpg");
	background->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	this->addChild(background);

	std::string dictionary[5] = { "knight", "paladin", "rogue", "assassin", "wizard" };
	Sprite* character = Sprite::create(dictionary[characterDecision] + ".png");
	character->setScale(0.5);
	character->setPosition(visibleSize.width / 2, visibleSize.height / 2 - 150);
	this->addChild(character);

	weapon[0] = Sprite::create("quickgun.png");
	weapon[1] = Sprite::create("submachinegun.png");
	weapon[2] = Sprite::create("sword.png");
	weapon[3] = Sprite::create("magicsword.png");
	
	CallFuncN* actionAppearRight = CallFuncN::create(CC_CALLBACK_1(ChoosingWeapon::appearRight, this));
	CallFuncN* actionAppearLeft = CallFuncN::create(CC_CALLBACK_1(ChoosingWeapon::appearLeft, this));
	CallFuncN* actionDisappear = CallFuncN::create(CC_CALLBACK_1(ChoosingWeapon::outScreen, this));
	CallFuncN* actionBig = CallFuncN::create(CC_CALLBACK_1(ChoosingWeapon::big, this));
	CallFuncN* actionTinyLeft = CallFuncN::create(CC_CALLBACK_1(ChoosingWeapon::tinyLeft, this));
	CallFuncN* actionTinyRight = CallFuncN::create(CC_CALLBACK_1(ChoosingWeapon::tinyRight, this));

	auto ok = MenuItemImage::create("fire.png", "fireSelected.png", CC_CALLBACK_1(ChoosingWeapon::menuOKCallback, this));
	ok->setPosition(visibleSize.width - ok->getContentSize().width / 2, ok->getContentSize().height / 2);
	auto rightItem = MenuItemImage::create("right.png", "rightSelected.png", CC_CALLBACK_1(ChoosingWeapon::menuRightCallback, this));
	rightItem->setPosition(visibleSize.width / 2 + 225, visibleSize.height / 2 - 50);
	auto leftItem = MenuItemImage::create("left.png", "leftSelected.png", CC_CALLBACK_1(ChoosingWeapon::menuLeftCallback, this));
	leftItem->setPosition(visibleSize.width / 2 - 225, visibleSize.height / 2 - 50);
	auto menu = Menu::create(ok, rightItem, leftItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu);

	this->addChild(weapon[0]);
	(weapon[0])->setScale(100 / (weapon[0])->getContentSize().width);
	this->addChild(weapon[1]);
	(weapon[1])->setScale(100 / (weapon[0])->getContentSize().width);
	this->addChild(weapon[2]);
	(weapon[2])->setScale(100 / (weapon[0])->getContentSize().width);
	this->addChild(weapon[3]);
	(weapon[3])->setScale(100 / (weapon[0])->getContentSize().width);
	(weapon[0])->runAction(Sequence::create(actionAppearRight, actionBig, NULL));
	(weapon[1])->runAction(Sequence::create(actionDisappear, NULL));
	(weapon[2])->runAction(Sequence::create(actionDisappear, NULL));
	(weapon[3])->runAction(Sequence::create(actionDisappear, NULL));

	return true;
}

void ChoosingWeapon::appearRight(Node* target)
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	target->setPosition(visibleSize.width / 2 + 225, visibleSize.height / 2 + 100);
	return;
}

void ChoosingWeapon::appearLeft(Node* target)
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	target->setPosition(visibleSize.width / 2 - 225, visibleSize.height / 2 + 100);
	return;
}

void ChoosingWeapon::outScreen(Node* target)
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	target->setPosition(-target->getContentSize().width, -target->getContentSize().height);
	return;
}

void ChoosingWeapon::big(Node* target)
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	target->runAction(MoveTo::create(0.5, Vec2(visibleSize.width / 2, visibleSize.height / 2 + 200)));
	target->runAction(ScaleTo::create(0.5, 4));
	return;
}

void ChoosingWeapon::tinyLeft(Node* target)
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	target->runAction(MoveTo::create(0.5, Vec2(visibleSize.width / 2 - 225, visibleSize.height / 2 + 100)));
	target->runAction(ScaleTo::create(0.5, 0.5));
	return;
}

void ChoosingWeapon::tinyRight(Node* target)
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	target->runAction(MoveTo::create(0.5, Vec2(visibleSize.width / 2 + 225, visibleSize.height / 2 + 100)));
	target->runAction(ScaleTo::create(0.5, 0.5));
	return;
}

void ChoosingWeapon::menuOKCallback(Ref* pSender)
{
	if (!decisionMade)
	{
		decisionMade++;
		weaponDecision[0] = currentID;
		auto visibleSize = Director::getInstance()->getVisibleSize();
		std::string dictionary[4] = { "quickgun", "submachinegun", "sword", "magicsword" };
		weaponDisplay[0] = Sprite::create(dictionary[currentID] + ".png");
		(weaponDisplay[0])->setScale(100 / (weaponDisplay[0])->getContentSize().width);
		(weaponDisplay[0])->setPosition(visibleSize.width / 2 - 100, visibleSize.height / 2 - 50);
		this->addChild(weaponDisplay[0]);
	}
	else if (currentID != weaponDecision[0])
	{
		weaponDecision[1] = currentID;
		auto visibleSize = Director::getInstance()->getVisibleSize();
		std::string dictionary[4] = { "quickgun", "submachinegun", "sword", "magicsword" };
		weaponDisplay[1] = Sprite::create(dictionary[currentID] + ".png");
		(weaponDisplay[1])->setScale(100 / (weaponDisplay[1])->getContentSize().width);
		(weaponDisplay[1])->setPosition(visibleSize.width / 2 + 100, visibleSize.height / 2 - 50);
		this->addChild(weaponDisplay[1]);
		Director::getInstance()->replaceScene(TransitionFade::create(0.5, Play11::createScene()));
	}
}

void ChoosingWeapon::menuRightCallback(Ref* pSender)
{
	if (currentID != 3)
	{
		CallFuncN* actionAppearRight = CallFuncN::create(CC_CALLBACK_1(ChoosingWeapon::appearRight, this));
		CallFuncN* actionAppearLeft = CallFuncN::create(CC_CALLBACK_1(ChoosingWeapon::appearLeft, this));
		CallFuncN* actionDisappear = CallFuncN::create(CC_CALLBACK_1(ChoosingWeapon::outScreen, this));
		CallFuncN* actionBig = CallFuncN::create(CC_CALLBACK_1(ChoosingWeapon::big, this));
		CallFuncN* actionTinyLeft = CallFuncN::create(CC_CALLBACK_1(ChoosingWeapon::tinyLeft, this));
		CallFuncN* actionTinyRight = CallFuncN::create(CC_CALLBACK_1(ChoosingWeapon::tinyRight, this));
		(weapon[currentID++])->runAction(Sequence::create(actionTinyLeft, DelayTime::create(0.5), actionDisappear, NULL));
		(weapon[currentID])->runAction(Sequence::create(actionAppearRight, actionBig, NULL));
	}
	return;
}

void ChoosingWeapon::menuLeftCallback(Ref* pSender)
{
	if (currentID != 0)
	{
		CallFuncN* actionAppearRight = CallFuncN::create(CC_CALLBACK_1(ChoosingWeapon::appearRight, this));
		CallFuncN* actionAppearLeft = CallFuncN::create(CC_CALLBACK_1(ChoosingWeapon::appearLeft, this));
		CallFuncN* actionDisappear = CallFuncN::create(CC_CALLBACK_1(ChoosingWeapon::outScreen, this));
		CallFuncN* actionBig = CallFuncN::create(CC_CALLBACK_1(ChoosingWeapon::big, this));
		CallFuncN* actionTinyLeft = CallFuncN::create(CC_CALLBACK_1(ChoosingWeapon::tinyLeft, this));
		CallFuncN* actionTinyRight = CallFuncN::create(CC_CALLBACK_1(ChoosingWeapon::tinyRight, this));
		(weapon[currentID--])->runAction(Sequence::create(actionTinyRight, DelayTime::create(0.5), actionDisappear, NULL));
		(weapon[currentID])->runAction(Sequence::create(actionAppearLeft, actionBig, NULL));
	}
	return;
}
