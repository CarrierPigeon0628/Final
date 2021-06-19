#include "Play11.h"
#include "ChoosingWeapon.h"
#include <cmath>
#include <iostream>

USING_NS_CC;

Scene* Play11::createScene()
{
    return Play11::create();
}

// on "init" you need to initialize your instance
bool Play11::init()
{

    //////////////////////////////
    // 1. super init first
    if (!Scene::init())
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    switch (ChoosingWeapon::characterDecision)
    {
    case 0:
        heroKnight = knight::create("knight.png");
        heroKnight->setScale(0.3f);
        this->addChild(heroKnight, 3);
        heroKnight->setPosition(visibleSize.width / 2, visibleSize.height / 2);
        break;
    case 1:
        heroPaladin = paladin::create("paladin.png");
        heroPaladin->setScale(0.3f);
        this->addChild(heroPaladin, 3);
        heroPaladin->setPosition(visibleSize.width / 2, visibleSize.height / 2);
        break;
    case 2:
        heroRogue = rogue::create("rogue.png");
        heroRogue->setScale(0.3f);
        this->addChild(heroRogue, 3);
        heroRogue->setPosition(visibleSize.width / 2, visibleSize.height / 2);
        break;
    case 3:
        heroAssassin = assassin::create("assassin.png");
        heroAssassin->setScale(0.3f);
        this->addChild(heroAssassin, 3);
        heroAssassin->setPosition(visibleSize.width / 2, visibleSize.height / 2);
        break;
    case 4:
        heroWizard = wizard::create("wizard.png");
        heroWizard->setScale(0.3f);
        this->addChild(heroWizard, 3);
        heroWizard->setPosition(visibleSize.width / 2, visibleSize.height / 2);
        break;
    }

    listener = EventListenerKeyboard::create();
    listener->onKeyPressed = CC_CALLBACK_2(Play11::onKeyPressed, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    Mlistener = EventListenerMouse::create();
    _eventDispatcher->addEventListenerWithSceneGraphPriority(Mlistener, this);
    this->scheduleUpdate();

    CallFuncN* actionAppear = CallFuncN::create(CC_CALLBACK_1(Play11::appear, this));
    CallFuncN* actionGive = CallFuncN::create(CC_CALLBACK_1(Play11::give, this));
    switch (ChoosingWeapon::weaponDecision[0])
    {
    case 0:
        quickGun = quickgun::create("quickgun.png");
        this->addChild(quickGun, 4);
        quickGun->runAction(Sequence::create(DelayTime::create(0.5), actionAppear, actionGive, NULL));
        break;
    case 1:
        SMG = submachinegun::create("submachinegun.png");
        this->addChild(SMG, 4);
        SMG->runAction(Sequence::create(DelayTime::create(0.5), actionAppear, actionGive, NULL));
        break;
    case 2:
        Sword = sword::create("sword.png");
        this->addChild(Sword, 4);
        Sword->runAction(Sequence::create(DelayTime::create(0.5), actionAppear, actionGive, NULL));
        break;
    case 3:
        magicSword = magicsword::create("magicsword.png");
        this->addChild(magicSword, 4);
        magicSword->runAction(Sequence::create(DelayTime::create(0.5), actionAppear, actionGive, NULL));
        break;
    }
    switch (ChoosingWeapon::weaponDecision[1])
    {
    case 0:
        quickGun = quickgun::create("quickgun.png");
        this->addChild(quickGun, 4);
        quickGun->setPosition(-quickGun->getContentSize().width, -quickGun->getContentSize().height);
        break;
    case 1:
        SMG = submachinegun::create("submachinegun.png");
        this->addChild(SMG, 4);
        SMG->setPosition(-SMG->getContentSize().width, -SMG->getContentSize().height);
        break;
    case 2:
        Sword = sword::create("sword.png");
        this->addChild(Sword, 4);
        Sword->setPosition(-Sword->getContentSize().width, -Sword->getContentSize().height);
        break;
    case 3:
        magicSword = magicsword::create("magicsword.png");
        this->addChild(magicSword, 4);
        magicSword->setPosition(-magicSword->getContentSize().width, -magicSword->getContentSize().height);
        break;
    }
    currentUse = ChoosingWeapon::weaponDecision[0];
    alternative = ChoosingWeapon::weaponDecision[1];
    return true;
}

void Play11::appear(Node* target)
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    target->setPosition(visibleSize.width / 2, visibleSize.height / 2 + 75);
    return;
}

void Play11::give(Node* target)
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    target->runAction(MoveTo::create(0.25, Vec2(visibleSize.width / 2, visibleSize.height / 2 - 10)));
    return;
}

void Play11::tiny(Node* target)
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    target->setPosition(visibleSize.width / 2, visibleSize.height / 2);
    target->setScale(0.0001f);
    target->setRotation(180);
    return;
}

void Play11::big(Node* target)
{
    target->runAction(ScaleTo::create(0.5f, 0.5));
    return;
}

void Play11::disappear(Node* target)
{
    target->setPosition(-target->getContentSize().width, -target->getContentSize().height);
    return;
}

void Play11::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
    if (keyCode == EventKeyboard::KeyCode::KEY_E)
    {
        int temp = currentUse;
        currentUse = alternative;
        alternative = temp;
        CallFuncN* actionAppear = CallFuncN::create(CC_CALLBACK_1(Play11::appear, this));
        CallFuncN* actionGive = CallFuncN::create(CC_CALLBACK_1(Play11::give, this));
        switch (currentUse)
        {
        case 0:
            quickGun->runAction(Sequence::create(actionAppear, actionGive, NULL));
            break;
        case 1:
            SMG->runAction(Sequence::create(actionAppear, actionGive, NULL));
            break;
        case 2:
            Sword->runAction(Sequence::create(actionAppear, actionGive, NULL));
            break;
        case 3:
            magicSword->runAction(Sequence::create(actionAppear, actionGive, NULL));
            break;
        }
        switch (alternative)
        {
        case 0:
            quickGun->setPosition(-quickGun->getContentSize().width, -quickGun->getContentSize().height);
            break;
        case 1:
            SMG->setPosition(-SMG->getContentSize().width, -SMG->getContentSize().height);
            break;
        case 2:
            Sword->setPosition(-Sword->getContentSize().width, -Sword->getContentSize().height);
            break;
        case 3:
            magicSword->setPosition(-magicSword->getContentSize().width, -magicSword->getContentSize().height);
            break;
        }
    }
}

void Play11::update(float delta) {
    Node::update(delta);
    Mlistener->onMouseMove = [=](Event* event)
    {
        EventMouse* e = (EventMouse*)event;
        auto visibleSize = Director::getInstance()->getVisibleSize();
        float a = atan((e->getCursorY() - (visibleSize.height / 2 - 10)) / (e->getCursorX() - visibleSize.width / 2));
        a = -a * 180 / (4 * atan(1));
        if (e->getCursorX() - visibleSize.width / 2 == 0 && e->getCursorY() - (visibleSize.height / 2 - 10) > 0) a = -90;
        else if (e->getCursorX() - visibleSize.width / 2 == 0 && e->getCursorY() - (visibleSize.height / 2 - 10) < 0) a = 90;
        switch (currentUse)
        {
        case 0:
            quickGun->setAnchorPoint(Point(-0.1f, 0.5f));
            quickGun->runAction(RotateTo::create(0.05f, a));
            break;
        case 1:
            SMG->setAnchorPoint(Point(-0.1f, 0.5f));
            SMG->runAction(RotateTo::create(0.05f, a));
            break;
        case 2:
            Sword->setAnchorPoint(Point(-0.1f, 0.5f));
            Sword->runAction(RotateTo::create(0.05f, a));
            break;
        case 3:
            magicSword->setAnchorPoint(Point(-0.1f, 0.5f));
            magicSword->runAction(RotateTo::create(0.05f, a));
        }
        switch (ChoosingWeapon::characterDecision)
        {
        case 0:
            if (e->getCursorX() < heroKnight->getPositionX())
            {
                auto scaleTo = ScaleTo::create(0.01f, -0.3f, 0.3f);
                heroKnight->runAction(scaleTo);
                auto scaleTo1 = ScaleTo::create(0.001f, -1, 1);
                switch (currentUse)
                {
                case 0:
                    quickGun->runAction(scaleTo1);
                    break;
                case 1:
                    SMG->runAction(scaleTo1);
                    break;
                case 2:
                    Sword->runAction(scaleTo1);
                    break;
                case 3:
                    magicSword->runAction(scaleTo1);
                    break;
                }
            }
            else {
                auto scaleTo = ScaleTo::create(0.001f, 0.3f, 0.3f);
                heroKnight->runAction(scaleTo);
                auto scaleTo1 = ScaleTo::create(0.001f, 1, 1);
                switch (currentUse)
                {
                case 0:
                    quickGun->runAction(scaleTo1);
                    break;
                case 1:
                    SMG->runAction(scaleTo1);
                    break;
                case 2:
                    Sword->runAction(scaleTo1);
                    break;
                case 3:
                    magicSword->runAction(scaleTo1);
                    break;
                }
            }
            break;
        case 1:
            if (e->getCursorX() < heroPaladin->getPositionX())
            {
                auto scaleTo = ScaleTo::create(0.01f, -0.3f, 0.3f);
                heroPaladin->runAction(scaleTo);
                auto scaleTo1 = ScaleTo::create(0.001f, -1, 1);
                switch (currentUse)
                {
                case 0:
                    quickGun->runAction(scaleTo1);
                    break;
                case 1:
                    SMG->runAction(scaleTo1);
                    break;
                case 2:
                    Sword->runAction(scaleTo1);
                    break;
                case 3:
                    magicSword->runAction(scaleTo1);
                    break;
                }
            }
            else {
                auto scaleTo = ScaleTo::create(0.001f, 0.3f, 0.3f);
                heroPaladin->runAction(scaleTo);
                auto scaleTo1 = ScaleTo::create(0.001f, 1, 1);
                switch (currentUse)
                {
                case 0:
                    quickGun->runAction(scaleTo1);
                    break;
                case 1:
                    SMG->runAction(scaleTo1);
                    break;
                case 2:
                    Sword->runAction(scaleTo1);
                    break;
                case 3:
                    magicSword->runAction(scaleTo1);
                    break;
                }
            }
            break;
        case 2:
            if (e->getCursorX() < heroRogue->getPositionX())
            {
                auto scaleTo = ScaleTo::create(0.01f, -0.3f, 0.3f);
                heroRogue->runAction(scaleTo);
                auto scaleTo1 = ScaleTo::create(0.001f, -1, 1);
                switch (currentUse)
                {
                case 0:
                    quickGun->runAction(scaleTo1);
                    break;
                case 1:
                    SMG->runAction(scaleTo1);
                    break;
                case 2:
                    Sword->runAction(scaleTo1);
                    break;
                case 3:
                    magicSword->runAction(scaleTo1);
                    break;
                }
            }
            else {
                auto scaleTo = ScaleTo::create(0.001f, 0.3f, 0.3f);
                heroRogue->runAction(scaleTo);
                auto scaleTo1 = ScaleTo::create(0.001f, 1, 1);
                switch (currentUse)
                {
                case 0:
                    quickGun->runAction(scaleTo1);
                    break;
                case 1:
                    SMG->runAction(scaleTo1);
                    break;
                case 2:
                    Sword->runAction(scaleTo1);
                    break;
                case 3:
                    magicSword->runAction(scaleTo1);
                    break;
                }
            }
            break;
        case 3:
            if (e->getCursorX() < heroAssassin->getPositionX())
            {
                auto scaleTo = ScaleTo::create(0.01f, -0.3f, 0.3f);
                heroAssassin->runAction(scaleTo);
                auto scaleTo1 = ScaleTo::create(0.001f, -1, 1);
                switch (currentUse)
                {
                case 0:
                    quickGun->runAction(scaleTo1);
                    break;
                case 1:
                    SMG->runAction(scaleTo1);
                    break;
                case 2:
                    Sword->runAction(scaleTo1);
                    break;
                case 3:
                    magicSword->runAction(scaleTo1);
                    break;
                }
            }
            else {
                auto scaleTo = ScaleTo::create(0.001f, 0.3f, 0.3f);
                heroAssassin->runAction(scaleTo);
                auto scaleTo1 = ScaleTo::create(0.001f, 1, 1);
                switch (currentUse)
                {
                case 0:
                    quickGun->runAction(scaleTo1);
                    break;
                case 1:
                    SMG->runAction(scaleTo1);
                    break;
                case 2:
                    Sword->runAction(scaleTo1);
                    break;
                case 3:
                    magicSword->runAction(scaleTo1);
                    break;
                }
            }
            break;
        case 4:
            if (e->getCursorX() < heroWizard->getPositionX())
            {
                auto scaleTo = ScaleTo::create(0.01f, -0.3f, 0.3f);
                heroWizard->runAction(scaleTo);
                auto scaleTo1 = ScaleTo::create(0.001f, -1, 1);
                switch (currentUse)
                {
                case 0:
                    quickGun->runAction(scaleTo1);
                    break;
                case 1:
                    SMG->runAction(scaleTo1);
                    break;
                case 2:
                    Sword->runAction(scaleTo1);
                    break;
                case 3:
                    magicSword->runAction(scaleTo1);
                    break;
                }
            }
            else {
                auto scaleTo = ScaleTo::create(0.001f, 0.3f, 0.3f);
                heroWizard->runAction(scaleTo);
                auto scaleTo1 = ScaleTo::create(0.001f, 1, 1);
                switch (currentUse)
                {
                case 0:
                    quickGun->runAction(scaleTo1);
                    break;
                case 1:
                    SMG->runAction(scaleTo1);
                    break;
                case 2:
                    Sword->runAction(scaleTo1);
                    break;
                case 3:
                    magicSword->runAction(scaleTo1);
                    break;
                }
            }
            break;
        }

    };
    Mlistener->onMouseDown = [=](Event* event)
    {
        EventMouse* e = (EventMouse*)event;
        auto visibleSize = Director::getInstance()->getVisibleSize();
        bullet* Bullet1 = bullet::create("bullet.png");
        bullet* Bullet2 = bullet::create("bullet.png");
        bullet* Bullet3 = bullet::create("bullet.png");
        bullet* Bullet4 = bullet::create("bullet.png");
        bullet* Bullet5 = bullet::create("bullet.png");
        magic* magic = magic::create("magic.png");
        CallFuncN* tiny = CallFuncN::create(CC_CALLBACK_1(Play11::tiny, this));
        CallFuncN* big = CallFuncN::create(CC_CALLBACK_1(Play11::big, this));
        CallFuncN* disappear = CallFuncN::create(CC_CALLBACK_1(Play11::disappear, this));
        switch (currentUse)
        {
        case 0:
            this->addChild(Bullet1, 2);
            Bullet1->setPosition(visibleSize.width / 2, visibleSize.height / 2 - 10);
            Bullet1->setScale(0.5f);
            Bullet1->runAction(MoveTo::create(0.5f, quickgun::GetTarget(Point(visibleSize.width / 2, visibleSize.height / 2 - 10), Point(e->getCursorX(), e->getCursorY()), 20, 20)));
            break;
        case 1:
            this->addChild(Bullet1, 2);
            Bullet1->setPosition(visibleSize.width / 2, visibleSize.height / 2 - 10);
            Bullet1->setScale(0.5f);
            Bullet1->runAction(MoveTo::create(0.5f, submachinegun::GetTarget(Point(visibleSize.width / 2, visibleSize.height / 2 - 10), submachinegun::TargetRotation(Point(visibleSize.width / 2, visibleSize.height / 2 - 10), Point(e->getCursorX(), e->getCursorY()), 0), 20, 20)));
            this->addChild(Bullet2, 2);
            Bullet2->setPosition(visibleSize.width / 2, visibleSize.height / 2 - 10);
            Bullet2->setScale(0.5f);
            Bullet2->runAction(MoveTo::create(0.5f, submachinegun::GetTarget(Point(visibleSize.width / 2, visibleSize.height / 2 - 10), submachinegun::TargetRotation(Point(visibleSize.width / 2, visibleSize.height / 2 - 10), Point(e->getCursorX(), e->getCursorY()), 45), 20, 20)));
            this->addChild(Bullet3, 2);
            Bullet3->setPosition(visibleSize.width / 2, visibleSize.height / 2 - 10);
            Bullet3->setScale(0.5f);
            Bullet3->runAction(MoveTo::create(0.5f, submachinegun::GetTarget(Point(visibleSize.width / 2, visibleSize.height / 2 - 10), submachinegun::TargetRotation(Point(visibleSize.width / 2, visibleSize.height / 2 - 10), Point(e->getCursorX(), e->getCursorY()), -45), 20, 20)));
            this->addChild(Bullet4, 2);
            Bullet4->setPosition(visibleSize.width / 2, visibleSize.height / 2 - 10);
            Bullet4->setScale(0.5f);
            Bullet4->runAction(MoveTo::create(0.5f, submachinegun::GetTarget(Point(visibleSize.width / 2, visibleSize.height / 2 - 10), submachinegun::TargetRotation(Point(visibleSize.width / 2, visibleSize.height / 2 - 10), Point(e->getCursorX(), e->getCursorY()), 22.5), 20, 20)));
            this->addChild(Bullet5, 2);
            Bullet5->setPosition(visibleSize.width / 2, visibleSize.height / 2 - 10);
            Bullet5->setScale(0.5f);
            Bullet5->runAction(MoveTo::create(0.5f, submachinegun::GetTarget(Point(visibleSize.width / 2, visibleSize.height / 2 - 10), submachinegun::TargetRotation(Point(visibleSize.width / 2, visibleSize.height / 2 - 10), Point(e->getCursorX(), e->getCursorY()), -22.5), 20, 20)));
            break;
        case 2:
            if (e->getCursorX() > visibleSize.width / 2)
                Sword->runAction(Sequence::create(RotateBy::create(0.075f, -40), RotateBy::create(0.15f, 80), RotateBy::create(0.075f, -40), NULL));
            else
                Sword->runAction(Sequence::create(RotateBy::create(0.075f, 40), RotateBy::create(0.15f, -80), RotateBy::create(0.075f, 40), NULL));
            break;
        case 3:
            if (e->getCursorX() > visibleSize.width / 2)
                magicSword->runAction(Sequence::create(RotateBy::create(0.075f, -40), RotateBy::create(0.15f, 80), RotateBy::create(0.075f, -40), NULL));
            else
                magicSword->runAction(Sequence::create(RotateBy::create(0.075f, 40), RotateBy::create(0.15f, -80), RotateBy::create(0.075f, 40), NULL));
            this->addChild(magic, 2);
            magic->runAction(Sequence::create(tiny, big, RotateBy::create(0.5f, 180), DelayTime::create(0.25f), disappear, NULL));
            break;
        }
        
    };
}
