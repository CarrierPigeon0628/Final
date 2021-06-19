#ifndef __CHOOSINGCHARACTER_SCENE_H__
#define __CHOOSINGCHARACTER_SCENE_H__

#include "cocos2d.h"

class ChoosingCharacter :public cocos2d::Scene
{
public:
	cocos2d::Sprite* character[5] = { 0 };
	int currentID = 0;
	static int decision;

	static cocos2d::Scene* createScene();

	virtual bool init();

	void appear(cocos2d::Node* target);
	void slide(cocos2d::Node* target);

	void menuOKCallback(cocos2d::Ref* pSender);
	void menuRightCallback(cocos2d::Ref* pSender);
	void menuLeftCallback(cocos2d::Ref* pSender);

	CREATE_FUNC(ChoosingCharacter);
};

#endif // __CHOOSINGCHARACTER_SCENE_H__
