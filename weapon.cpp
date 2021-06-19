#include "weapon.h"
#include <cmath>
USING_NS_CC;
quickgun* quickgun::create(const char* picFileName)
{
    quickgun* sprite = new quickgun();

    if (sprite && sprite->initWithFile(picFileName))
    {
        sprite->autorelease();
        return sprite;
    }

    CC_SAFE_DELETE(sprite);
    return nullptr;
}
bool quickgun::init()
{
    if (!Sprite::init()) return false;
    return true;
}

Point quickgun::GetTarget(Point start, Point end, int Xout, int Yout)
{
    float fk = 1.0; float fb = 0.0;
    if (start.x != end.x)
    {
        fk = (float)(start.y - end.y) / (start.x - end.x);
    }
    fb = start.y - start.x * fk;
    auto visibleSize = Director::getInstance()->getVisibleSize();
    float fy = start.y > end.y ? -Yout : visibleSize.height + Yout;
    float fx = 1.0;
    if (fk != 0) { fx = (fy - fb) / fk; }
    if (start.x == end.x) { fx = start.x; fy = start.y > end.y ? -Yout : visibleSize.height + Yout; }
    else if (end.y == start.y) { fx = start.x > end.x ? -Xout : visibleSize.width + Xout; fy = start.y; }
    else if (fx > visibleSize.width + Xout) { fx = visibleSize.width + Xout; fy = fk * fx + fb; }
    else if (fx < -Xout) { fx = -Xout; fy = fk * fx + fb; }
    return Point(fx, fy);
}

submachinegun* submachinegun::create(const char* picFileName)
{
    submachinegun* sprite = new submachinegun();

    if (sprite && sprite->initWithFile(picFileName))
    {
        sprite->autorelease();
        return sprite;
    }

    CC_SAFE_DELETE(sprite);
    return nullptr;
}
bool submachinegun::init()
{
    if (!Sprite::init()) return false;
    return true;
}

Point submachinegun::TargetRotation(Point start, Point end, float angle)
{
    angle = angle * (4 * atan(1)) / 180;
    float ak = atan((end.y - start.y) / (end.x - start.x));
    if (end.x < start.x)
        if (ak > 0) ak -= 4 * atan(1);
        else ak += 4 * atan(1);
    ak += angle;
    return Point(start.x + 100 * cos(ak), start.y + 100 * sin(ak));
}

Point submachinegun::GetTarget(Point start, Point end, int Xout, int Yout)
{
    float fk = 1.0; float fb = 0.0;
    if (start.x != end.x)
    {
        fk = (float)(start.y - end.y) / (start.x - end.x);
    }
    fb = start.y - start.x * fk;
    auto visibleSize = Director::getInstance()->getVisibleSize();
    float fy = start.y > end.y ? -Yout : visibleSize.height + Yout;
    float fx = 1.0;
    if (fk != 0) { fx = (fy - fb) / fk; }
    if (start.x == end.x) { fx = start.x; fy = start.y > end.y ? -Yout : visibleSize.height + Yout; }
    else if (end.y == start.y) { fx = start.x > end.x ? -Xout : visibleSize.width + Xout; fy = start.y; }
    else if (fx > visibleSize.width + Xout) { fx = visibleSize.width + Xout; fy = fk * fx + fb; }
    else if (fx < -Xout) { fx = -Xout; fy = fk * fx + fb; }
    return Point(fx, fy);
}

sword* sword::create(const char* picFileName)
{
    sword* sprite = new sword();

    if (sprite && sprite->initWithFile(picFileName))

    {
        sprite->autorelease(); return sprite;
    }

    CC_SAFE_DELETE(sprite);
    return nullptr;
}
bool sword::init()
{
    this->harm;
    return true;
}

magicsword* magicsword::create(const char* picFileName)
{
    magicsword* sprite = new magicsword();

    if (sprite && sprite->initWithFile(picFileName))

    {
        sprite->autorelease(); return sprite;
    }

    CC_SAFE_DELETE(sprite);
    return nullptr;
}
bool magicsword::init()
{
    this->harm;
    return true;
}

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

bool magic::init()
{
    this->harm;
    return true;
}
magic* magic::create(const char* picFileName)
{
    magic* sprite = new magic();

    if (sprite && sprite->initWithFile(picFileName))

    {
        sprite->autorelease();
        return sprite;
    }

    CC_SAFE_DELETE(sprite);
    return nullptr;
}
