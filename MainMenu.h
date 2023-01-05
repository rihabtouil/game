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

#ifndef __MAIN_MENU_H__
#define __MAIN_MENU_H__
#include "cocos2d.h"
 //class newScene
class NewScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	// a selector callback
	void menuCloseCallback(cocos2d::Ref* pSender);

	// implement the "static create()" method manually
	
	
	cocos2d::Sprite* mySprite;
	cocos2d::Sprite* hero1;
	cocos2d::Sprite* coin1;
	
	cocos2d::Sprite* damage;
	cocos2d::Sprite* gr1;
	cocos2d::Sprite* gr2;
	cocos2d::Sprite* gr3;
	cocos2d::Sprite* tv;
	
	

    CREATE_FUNC(NewScene);
//private :
	//A world container is what your physics bodies are added to and where they are simulated
	//the interaction with PhysicsWorld object.
	cocos2d::PhysicsWorld* sceneWorld;
	
	void SetPhysicsWorld(cocos2d::PhysicsWorld* World) { sceneWorld = World ; };
	bool NewScene::onContact(cocos2d::PhysicsContact& contact);
	int posX = 0;
	int posY = 0;
	int count = 0;
    void update(float dt);
	};

#endif // __MAIN_MENU_H__