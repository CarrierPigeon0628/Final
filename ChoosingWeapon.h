#ifndef __CHOOSINGWEAPON_SCENE_H__
#define __CHOOSINGWEAPON_SCENE_H__

#include "cocos2d.h"

class ChoosingWeapon :public cocos2d::Scene
{
public:
	static int characterDecision;
	static int weaponDecision[2];
	cocos2d::Sprite* weapon[4] = { 0 };
	cocos2d::Sprite* weaponDisplay[2] = { 0 };
	int currentID = 0;
	int decisionMade = 0;

	static cocos2d::Scene* createScene();

	virtual bool init();

	void appearRight(cocos2d::Node* target);
	void appearLeft(cocos2d::Node* target);
	void outScreen(cocos2d::Node* target);
	void big(cocos2d::Node* target);
	void tinyLeft(cocos2d::Node* target);
	void tinyRight(cocos2d::Node* target);

	void menuOKCallback(cocos2d::Ref* pSender);
	void menuRightCallback(cocos2d::Ref* pSender);
	void menuLeftCallback(cocos2d::Ref* pSender);

	CREATE_FUNC(ChoosingWeapon);
};

#endif // __CHOOSINGWEAPON_SCENE_H__
