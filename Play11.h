#ifndef __PLAY11_SCENE_H__
#define __PLAY11_SCENE_H__

#include "cocos2d.h"
#include "character.h"
#include "weapon.h"

class Play11 :public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    cocos2d::EventListenerKeyboard* listener = 0;
    cocos2d::EventListenerMouse* Mlistener = 0;

    virtual bool init();

    void update(float delta) override;

    void appear(cocos2d::Node* target);
    void give(cocos2d::Node* target);
    void tiny(cocos2d::Node* target);
    void big(cocos2d::Node* target);
    void disappear(cocos2d::Node* target);

    void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
    CREATE_FUNC(Play11);
private:
    int currentUse = 0, alternative = 0;

    std::map<cocos2d::EventKeyboard::KeyCode, bool> keys;
    knight* heroKnight = 0;
    paladin* heroPaladin = 0;
    rogue* heroRogue = 0;
    assassin* heroAssassin = 0;
    wizard* heroWizard = 0;
    quickgun* quickGun = 0;
    submachinegun* SMG = 0;
    sword* Sword = 0;
    magicsword* magicSword = 0;
};

#endif // __PLAY11_SCENE_H__
