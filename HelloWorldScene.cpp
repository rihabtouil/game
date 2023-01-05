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

#include "HelloWorldScene.h"
#include"MainMenu.h"
#include"AudioEngine.h"






USING_NS_CC;

Scene* HelloWorld::createScene()
{
	auto scene = Scene::create();

	
	auto layer = HelloWorld::create();

	
	scene->addChild(layer);

	
	return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
	
	if (!Layer::init())
	{
		return false;
	}
	
	//--------------CC_CALLBACK_1 function called when the button is tapped on , 1 nbre of parameters
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	//------------------------l'image de plan d'arrier----------------
	
	mySprite = Sprite::create("img1.png");
	mySprite->setPosition(Point((visibleSize.width / 2) + origin.x, (visibleSize.height / 2) + 120 + origin.y));
	this->addChild(mySprite);
	{ 
	auto carac = Sprite::create("carac.png");
	carac->setPosition(Point((visibleSize.width / 2) + origin.x, (visibleSize.height / 2) +198 + origin.y));
	carac->setScale(1.7);
	this->addChild(carac ,7);
	}
	//-----------------creer shutdown ------------------
	auto menu_item = MenuItemImage::create("quit.png", "quit.png", CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
	menu_item->setPosition(Point((visibleSize.width / 2) + origin.x, (visibleSize.height / 2) + origin.y));
	//---------------MainMenu----------------------------
	
	
	auto play = MenuItemImage::create("play.png", "play.png", CC_CALLBACK_1(HelloWorld::GoToGameScene, this));
	play->setPosition(Point((visibleSize.width / 2) + origin.x, (visibleSize.height / 2)+100 + origin.y));


	
	
	auto* menu = Menu::create(menu_item, play ,NULL);
	menu->setPosition(Point(0, 0));
	this->addChild(menu);
	

	
	
	return true;
}


void HelloWorld::GoToGameScene(Ref* prender)
{
	auto scene = NewScene::createScene();
	Director::getInstance()->replaceScene(scene);
} 

void HelloWorld::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.", "Alert");
	return;
#endif

	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}




