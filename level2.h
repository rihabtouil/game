/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#ifndef __level2_H__
#define __level2_H__
#include "cocos2d.h"

class Level2 : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	cocos2d::PhysicsWorld* sceneWorld;

	void SetPhysicsWorld(cocos2d::PhysicsWorld* World) { sceneWorld = World; };
	bool Level2::onContact(cocos2d::PhysicsContact& contact);

	void menuCloseCallback(cocos2d::Ref* pSender);
	int posX = 0;
	int posY = 0;
	void update(float dt);
	int count = 0;

	CREATE_FUNC(Level2);

	cocos2d::Sprite* bg;
	cocos2d::Sprite* hero1;
	cocos2d::Sprite* coin2;
	cocos2d::Sprite* tv;
	cocos2d::Sprite* gr1;
	cocos2d::Sprite* gr2;
	cocos2d::Sprite* gr3;
	cocos2d::Sprite* gr4;
	cocos2d::Sprite* coin1;
};

#endif // __MAIN_MENU_H__