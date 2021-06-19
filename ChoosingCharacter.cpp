#include "ChoosingCharacter.h"
#include "ChoosingWeapon.h"

USING_NS_CC;

int ChoosingCharacter::decision;

Scene* ChoosingCharacter::createScene()
{
	return ChoosingCharacter::create();
}

bool ChoosingCharacter::init()
{
	if (!Scene::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Sprite* background = Sprite::create("ChoosingCharacter.jpg");
	background->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	this->addChild(background);
	
	character[0] = Sprite::create("knight.png");
	character[1] = Sprite::create("paladin.png");
	character[2] = Sprite::create("rogue.png");
	character[3] = Sprite::create("assassin.png");
	character[4] = Sprite::create("wizard.png");

	CallFuncN* actionAppear = CallFuncN::create(CC_CALLBACK_1(ChoosingCharacter::appear, this));
	CallFuncN* actionSlide = CallFuncN::create(CC_CALLBACK_1(ChoosingCharacter::slide, this));
	Sequence* action = Sequence::create(actionAppear, actionSlide, NULL);

	auto ok = MenuItemImage::create("fire.png", "fireSelected.png", CC_CALLBACK_1(ChoosingCharacter::menuOKCallback, this));
	ok->setPosition(visibleSize.width - ok->getContentSize().width / 2, ok->getContentSize().height / 2);
	auto rightItem = MenuItemImage::create("right.png", "rightSelected.png", CC_CALLBACK_1(ChoosingCharacter::menuRightCallback, this));
	rightItem->setPosition(visibleSize.width / 2 + 225, visibleSize.height / 2 - 50);
	auto leftItem = MenuItemImage::create("left.png", "leftSelected.png", CC_CALLBACK_1(ChoosingCharacter::menuLeftCallback, this));
	leftItem->setPosition(visibleSize.width / 2 - 225, visibleSize.height / 2 - 50);
	auto menu = Menu::create(ok, rightItem, leftItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu);

	this->addChild(character[0]);
	this->addChild(character[1]);
	this->addChild(character[2]);
	this->addChild(character[3]);
	this->addChild(character[4]);
	(character[0])->runAction(action);
	(character[1])->setPosition(-(character[1])->getContentSize().width, -(character[1])->getContentSize().height);
	(character[2])->setPosition(-(character[2])->getContentSize().width, -(character[2])->getContentSize().height);
	(character[3])->setPosition(-(character[3])->getContentSize().width, -(character[3])->getContentSize().height);
	(character[4])->setPosition(-(character[4])->getContentSize().width, -(character[4])->getContentSize().height);

	return true;
}

void ChoosingCharacter::appear(Node* target)
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	target->setPosition(visibleSize.width / 2, visibleSize.height / 2 + 150);
	target->setScale(0.5);
	return;
}

void ChoosingCharacter::slide(Node* target)
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	target->runAction(MoveTo::create(0.5, Vec2(visibleSize.width / 2, visibleSize.height / 2 - 50)));
	target->runAction(ScaleTo::create(0.5, 2));
	return;
}

void ChoosingCharacter::menuOKCallback(Ref* pSender)
{
	decision = currentID;
	Director::getInstance()->replaceScene(TransitionFade::create(0.5, ChoosingWeapon::createScene()));
	return;
}

void ChoosingCharacter::menuRightCallback(Ref* pSender)
{
	if (currentID != 4)
	{
		(character[currentID++])->setPosition(-(character[currentID])->getContentSize().width, -(character[currentID])->getContentSize().height);
		CallFuncN* actionAppear = CallFuncN::create(CC_CALLBACK_1(ChoosingCharacter::appear, this));
		CallFuncN* actionSlide = CallFuncN::create(CC_CALLBACK_1(ChoosingCharacter::slide, this));
		Sequence* action = Sequence::create(actionAppear, actionSlide, NULL);
		(character[currentID])->runAction(action);
	}
	return;
}

void ChoosingCharacter::menuLeftCallback(Ref* pSender)
{
	if (currentID != 0)
	{
		(character[currentID--])->setPosition(-(character[currentID])->getContentSize().width, -(character[currentID])->getContentSize().height);
		CallFuncN* actionAppear = CallFuncN::create(CC_CALLBACK_1(ChoosingCharacter::appear, this));
		CallFuncN* actionSlide = CallFuncN::create(CC_CALLBACK_1(ChoosingCharacter::slide, this));
		Sequence* action = Sequence::create(actionAppear, actionSlide, NULL);
		(character[currentID])->runAction(action);
	}
	return;
}
